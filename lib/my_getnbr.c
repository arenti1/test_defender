/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** my_getnbr
*/

#include "../include/my.h"

int my_getnbr(char *str)
{
    int val;
    int index;

    val = 0;
    index = 0;
    while (str[index] != '\0'){
        if (str[index] >= '0' && str[index] <= '9'){
            val = val*10;
            val = val + (str[index] - 48);
        } else {
            return (val);
        }
        index++;
    }
    return (val);
}
