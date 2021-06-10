/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char *string)
{
    int index = 0;
    char *storage = malloc(my_strlen(string) + 1);

    while (string[index] != '\0'){
        storage[index] = string[index];
        index++;
    }
    storage[index] = '\0';
    return (storage);
}
