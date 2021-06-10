/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** my_putchar
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_err(char c)
{
    write(2, &c, 1);
}