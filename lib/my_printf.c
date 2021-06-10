/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf
*/

#include "../include/my.h"

int my_binaryconverter(int n)
{
    int i = 1;
    int j;
    int binno = 0;
    int dn;

    dn = n;
    while (j > 0){
        j = n;
        j = j / 2;
        binno = binno + (n % 2) * i;
        i = i * 10;
        n = n / 2;
    }
    return binno;
}

void my_printf(char *str, ...)
{
    int len = my_strlen(str);
    int i = 0;
    va_list list;

    va_start(list, str);
    while (i < len){
        if ((str[i] == '%') && (str[i + 1] == 'd')){
            my_put_nbr(va_arg(list, int));
            i = i + 1;
        }
        else if ((str[i] == '%') && (str[i + 1] == 's')){
            my_putstr(va_arg(list, char *));
            i = i + 1;
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(list);
}

