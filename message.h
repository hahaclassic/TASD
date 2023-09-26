#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#define TITLE "Программа производит умножение ЦЕЛОГО числа на ДЕЙСТВИТЕЛЬНОЕ\n\n"

#define RULES_FLOAT "\nПравила ввода действительного числа:\n" \
    "\t- Число вводится в виде: [+/-]m.n[Е/e][+|-]K\n\t- Суммарная длина мантиссы (m + n) <= 30 значащих цифр\n\t- Величина порядка К <= 5 цифр\n\n"

#define INPUT_FLOAT "\t\t\t     >+---------1---------2---------3---------4---------5\nВведите ДЕЙСТВИТЕЛЬНОЕ число: "

#define RULES_INT "\nПравила ввода целого числа:\n" \
    "\t- Число вводится в виде: [+/-]m \n\t- Длина m <= 40 значащих цифр\n"

#define INPUT_INT "\t\t    >+---------1---------2---------3---------4---------5\nВведите ЦЕЛОЕ число: "
    
void show_menu(void);
void message(char *const message);

#endif
