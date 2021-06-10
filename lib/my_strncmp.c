/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** my_strncmp
*/

#include "../include/my.h"

int my_strncmp(char *str1, char *str2, int length)
{
    int index = 0;

    while (str1[index] != '\0' && str2[index] != '\0' && index < length-1) {
        if (str1[index] != str2[index])
            return (str1[index] - str2[index]);
        index++;
    }
    return (str1[index] - str2[index]);
}