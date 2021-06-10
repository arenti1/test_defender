/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char *source)
{
    int index = 0;
    int length = my_strlen(dest);

    while (source[index] != '\0'){
        dest[length + index] = source[index];
        index++;
    }
    dest[length + index] = '\0';
    return (dest);
}
