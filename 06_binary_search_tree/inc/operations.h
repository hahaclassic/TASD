#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include <stdio.h>
#include "errors.h"
#include "tree.h"
#include "timer.h"
#include "writer.h"
#include "reader.h"

#define MENU "\n=========================================================================================\n" \
             "|      Рализация работы с файловой директорией с помощью различных деревьев поиска      |\n" \
             "-----------------------------------------------------------------------------------------\n" \
             "| Операции                                                                              |\n" \
             "|---------------------------------------------------------------------------------------|\n" \
             "| 1. Добавить файл в директорию.                                                        |\n" \
             "| 2. Удалить файл из директории (Удаление по имени).                                    |\n" \
             "| 3. Удалить все файлы из директории, обращение к которым происходило до указанной      |\n" \
             "| даты, используя бинарное дерево поиска, построенное по алфавиту.                      |\n" \
             "| 4. Удалить все файлы из директории, обращение к которым происходило до указанной      |\n" \
             "| даты, используя бинарное дерево поиска, построенное по датам последнего обращения.    |\n" \
             "| 5. Сравнение эффективности двух реализаций.                                           |\n" \
             "| 6. Показать директорию в текущий момент.                                              |\n" \
             "|                                                                                       |\n" \
             "| 0. Выход из программы.                                                                |\n" \
             "|---------------------------------------------------------------------------------------|\n" \


#define INPUT_OUTPUT "| Входные данные                                                                        |\n" \
                     "|---------------------------------------------------------------------------------------|\n" \
                     "| Программа принимает на вход файлы в формате:                                          |\n" \
                     "|   -rwxrwxrwx ДД.ММ.ГГГГ ЧЧ:ММ имя_файла                                               |\n" \
                     "| где:                                                                                  |\n" \
                     "| 1. -rwxrwxrwx - права доступа к файлу. Начинается всегда с '-', т.к. можно добавлять  |\n" \
                     "| только файлы. Далее первые 3 буквы - права пользователя, следующие 3 - права группы,  |\n" \
                     "| и последние 3 буквы - права для остальных. 'r' - право на чтение, 'w' - право на      |\n" \
                     "| запись, 'x' - право на выполнение. Если указанного права нет, ставится '-'.           |\n" \
                     "| 2. ДД.ММ.ГГГГ ЧЧ:MM - дата последнего обращения к файлу.                              |\n" \
                     "| 3. имя_файла - имя файла не должно превышать 50 знаков. Может содержать латинские     |\n" \
                     "| буквы, арабские цифры, точку, нижнее подчеркивание и тире.                            |\n" \
                     "|                                                                                       |\n" \
                     "| В аргументах командой строки также можно указать входной и выходной файлы, откуда     |\n" \
                     "| можно считать начальные данные и записать результирующие.                             |\n" \
                     "|---------------------------------------------------------------------------------------|\n" \
                     "| Выходные данные                                                                       |\n" \
                     "|---------------------------------------------------------------------------------------|\n" \
                     "| Графическая визуализация данных помещается в .png файлы после каждой операции         |\n" \
                     "-----------------------------------------------------------------------------------------\n"

#define ENTER_OPERATION "\nВведите номер операции: "

typedef enum _operation
{
    /// Конец работы программы.
    END = 0,

    APPEND_FILE, 

    DELETE_FILE, 

    ALPHABET_BST_DELETE,

    DATE_BST_DELETE,

    TIMER,

    SHOW_FILES,
} operation_t;

void menu();

error_t choose_operation(operation_t *operation);

error_t delete_file_by_name(node_t **root);

error_t alpha_tree_delete_by_time(node_t **root);

error_t date_tree_delete_by_time(node_t *root);

error_t measure_time(node_t **root, unsigned long long *alpha_tree_time, 
    unsigned long long *date_tree_time, unsigned long long *convertation_time);

#endif