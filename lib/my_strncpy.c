/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** my_strncpy
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char *source, int n)
{
    int index = 0;
    while (source[index] != '\0' && index < n){
        dest[index] = source[index];
        index++;
    }
    dest[index] = '\0';
    return (dest);
}
