#include <stdio.h>
#include "stats.h"

#define MENU "=======================================================================================\n" \
             "| Проверка корректности последовательности из круглых, квадратных и фигурных скобок   |\n" \
             "---------------------------------------------------------------------------------------\n" \
             "| Если набор скобок не нарушает правила написания скобок в арифметических выражениях, |\n" \
             "| то данный набор считается корректным.                                               |\n" \
             "|                                                                                     |\n" \
             "|-------------------------------------------------------------------------------------|\n" \
             "| Операции                                                                            |\n" \
             "|-------------------------------------------------------------------------------------|\n" \
             "| 1. Проверка корректности с помомью стека в виде статического массива                |\n" \
             "| 2. Проверка корректности с помомью стека в виде односвязного списка                 |\n" \
             "| 3. Проверка корректности с помомью стека в виде статического массива (с доп. инфо)  |\n" \
             "| 4. Проверка корректности с помомью стека в виде односвязного списка (с доп. инфо)   |\n" \
             "| 5. Сравнение эффективности двух реализаций                                          |\n" \
             "|                                                                                     |\n" \
             "|-------------------------------------------------------------------------------------|\n" \
             "| Входные данные                                                                      |\n" \
             "|-------------------------------------------------------------------------------------|\n" \
             "| На вход программа принимает последовательность скобок, длина которой не более 1000. |\n" \
             "---------------------------------------------------------------------------------------\n"

#define ENTER_STR "Введите строку: "

#define RESULT_TRUE "\nРезультат: Данная последовательность корректна.\n\n"
#define RESULT_FALSE "\nРезультат: Данная последовательность некорректна.\n\n"

#define STATISTICS  "=======================================================================================\n" \
                    "|                            Сравнение эффективности                                  |\n" \
                    "---------------------------------------------------------------------------------------\n" \
                    "|              |      Стек в виде массива       |      Стек в виде связного списка    |\n" \
                    "|-------------------------------------------------------------------------------------|\n" \
                    "| Память, байт |      %-25ld |      %-30ld |\n" \
                    "|-------------------------------------------------------------------------------------|\n" \
                    "| Время, мкс   |      %-25ld |      %-30ld |\n" \
                    "=======================================================================================\n" 


void print_message(char *str);

void print_result(int result);

void print_statistics(size_t arr_time, size_t arr_mem, size_t list_time, size_t list_mem);

void print_free_nodes(stats_t *stats);
