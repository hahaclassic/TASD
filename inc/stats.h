#include "linked_list.h"

#ifndef STATS_T
#define STATS_T

//node_t* free_nodes[MAX_SIZE]; 

typedef struct stats_t
{
    size_t mode;
    size_t max; // Максимальный размер стека
    size_t curr; // Текущий размер стека
    node_t *free_nodes[MAX_SIZE];
    size_t n_nodes;
} stats_t;
#endif

void init_stats(stats_t *stats, int operation);

