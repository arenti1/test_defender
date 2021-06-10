/*
** EPITECH PROJECT, 2020
** my_nbrlen.c
** File description:
** my_nbrlen
*/

#include "../include/my.h"

int my_nbrlen(long n)
{
    long count = 0;

    while (n != 0){
        n = n / 10;
        count++;
    }
    return count;
}

