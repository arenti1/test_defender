/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "../include/my.h"

int my_strcmp(char *string1, char *string2)
{
    int index;
    index = 0;
    while (string1[index] != '\0' && string2[index] != '\0') {
        if (my_strlen(string1) == my_strlen(string2)) {
            return (string1[index] - string2[index]);
        }
        index++;
    }
    return (string1[index] - string2[index]);
}
