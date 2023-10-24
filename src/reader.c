#include "reader.h"


int readline(FILE *stream, int *row_idx, int *col_idx, double *val)
{
    if (fscanf(stream, "%d %d %lf", row_idx, col_idx, val) != 3) {
        return ERR_READ_DATA;
    }
    
    return STATUS_OK;
}

/* Reads amount of ROWS, COLS, and Non-null elements with validation */
int get_meta(FILE *stream, int *n_rows, int *n_cols, int *n_nz)
{
    if (fscanf(stream, "%d %d %lf", n_rows, n_cols, n_nz) != 3)
    {
        return ERR_INCORRECT_DATA;
    }

    if (*n_rows < 0 || *n_cols < 0 || *n_nz < 0) 
    {
        return ERR_INCORRECT_DATA;
    }
    if (*n_rows > MAX_SIZE || *n_cols > MAX_SIZE) 
    {
        return ERR_INCORRECT_MATRIX_SIZES;
    }
    if (*n_nz > (*n_rows) * (*n_cols)) 
    {
        return ERR_INCORRECT_DATA;
    }

    return STATUS_OK;
}

/* Reads matrices from stream */
int get_elements(FILE *stream, sparse_matrix_t *sparse, std_matrix_t *std)
{
    size_t nz = std->n_nz;

    int row_idx, col_idx;
    double val;

    for (size_t i = 0; i < nz; ++i) {
        
        if (stream == stdin)
        {
            printf("Введите элемент в формате i j value: ");
        }
        int err = readline(stream, &row_idx, &col_idx, &val);

        if (err) 
        {
            return err;
        }

        // Check the upper bound
        if (row_idx >= (int) std->rows || col_idx >= (int) std->columns) {
            return ERR_INCORRECT_DATA;
        }
        // Check lower bound
        if (row_idx < 0 || col_idx < 0) {
            return ERR_INCORRECT_DATA;
        }

        // Fill CSR
        //printf("COLIDX=%d ", col_idx);
        sparse->nums[i] = val;
        if (sparse->type)
        {
            sparse->idx[i] = col_idx;
            sparse->start[row_idx + 1]++;
        }
        else 
        {
            sparse->idx[i] = row_idx;
            sparse->start[col_idx + 1]++;
        }

        // Fill STD
        std->ptrs[ row_idx][col_idx] = val;
    }

    // Shift (idk what that is) 

    if (sparse->type)
    {
        for (size_t i = 0; i < sparse->n_rows; ++i) {
            sparse->start[i + 1] += sparse->start[i];
        }
    } 
    else
    {
        for (size_t i = 0; i < sparse->n_cols; ++i) {
            sparse->start[i + 1] += sparse->start[i];
        }
    }

    return STATUS_OK;
}


int read_matrix(FILE *file, sparse_matrix_t *sparse, std_matrix_t *std)
{
    if (file == stdin)
    {
        printf("Введите кол-во строк, столбцов и ненелувых элементов матрицы: ");
    }
   
    int n_rows, n_cols, n_nz;
    int err = get_meta(file, &n_rows, &n_cols, &n_nz);
    if (err)
    {
        return err;
    }

    err = set_sparse_matrix(sparse, n_rows, n_cols, n_nz, sparse->type);
    if (err)
    {
        return err;
    }

    std->rows = sparse->n_rows;
    std->columns = sparse->n_cols;
    std->n_nz = sparse->n_nz;

    std->ptrs = allocate_std_matrix(std->rows, std->columns);
    if (!std->ptrs)
    {
        free_sparse_matrix(sparse);
        return ERR_MEMORY_ALLOCATION;
    }

    err = get_elements(file, sparse, std);

    if (err)
    {
        free_std_matrix(std);
        free_sparse_matrix(sparse);
        return err;
    }

    return STATUS_OK;
}

int read_matrix_file(char *file_name, sparse_matrix_t *sparse, std_matrix_t *std)
{
    int err;
    FILE *file = fopen(file_name, "r");
    if (!file)
    {
        return ERR_FILE_OPEN;
    }

    err = read_matrix(file, sparse, std);
    fclose(file);
    if (err)
    {
        return err;
    }

    return STATUS_OK;
}
