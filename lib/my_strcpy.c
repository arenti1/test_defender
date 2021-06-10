/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char *source)
{
    int index = 0;
    while (source[index] != '\0'){
        dest[index] = source[index];
        index++;
    }
    dest[index] = '\0';
    return (dest);
}
