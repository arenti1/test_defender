/*
** EPITECH PROJECT, 2021
** my_str_world.c
** File description:
** my string to world
*/

#include "../include/my.h"

int how_many_words(char *string, char delim)
{
    int count = 0;
    int index = 0;

    if (string == NULL)
        return (84);
    while (string[index] != '\0') {
        if (string[index] == delim) {
            count++;
            while (string[index] == delim)
                index++;
            }
        index++;
    }
    return (count + 1);
}

int how_m_ch(char *string, int index, char delim)
{
    int char_nb = 0;

    while (string[index] != delim && string[index] != '\0') {
        char_nb++;
        index++;
    }
    return (char_nb);
}

char **my_str_to_word(char *string, char delim)
{
    char **a;
    int row = 0;
    int col = 0;
    int index = 0;
    a = malloc(sizeof(*a) * (how_many_words(string, delim) + 1));
    a[row] = malloc(sizeof(**a) * (how_m_ch(string, index, delim) + 1));

    while (string[index] != '\0') {
        if (string[index] == delim) {
            index++;
            a[row][col] = '\0';
            col = 0;
            row++;
            a[row] = malloc(sizeof(**a) * (how_m_ch(string, index, delim) + 1));
        }
        a[row][col++] = string[index++];
    }
    a[row][col] = '\0';
    a[row + 1] = NULL;
    return (a);
}

