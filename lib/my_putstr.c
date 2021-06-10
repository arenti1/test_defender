/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return 0;
}
