/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** my_realloc
*/

#include "../include/my.h"

char *my_realloc(char *string, int newsize)
{
    char *try = malloc(newsize);
    my_strcpy(try, string);
    free(string);
    return (try);
}
