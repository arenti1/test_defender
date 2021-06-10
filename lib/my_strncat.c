/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** my_strncat
*/

#include "../include/my.h"

char *my_strncat(char *dest, char *source, int n)
{
    int index = 0;
    int length = my_strlen(dest);

    while (source[index] != '\0' && index < n){
        dest[length + index] = source[index];
        index++;
    }
    dest[length + index] = '\0';
    return (dest);
}

