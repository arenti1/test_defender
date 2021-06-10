/*
** EPITECH PROJECT, 2020
** my_count_words.c
** File description:
** my_count_word
*/

#include "../include/my.h"

int my_count_words(char *str)
{
    int n = 0;
    int i = 0;
    while (str[i] != '\0'){
        if (str[i - 1] == ' ' && is_char_alpha(str[i]) == 1){
            n++;
        }
        else if (i == 0 && is_char_alpha(str[i]) == 1){
            n++;
        }
        i++;
    }
    return n;
}