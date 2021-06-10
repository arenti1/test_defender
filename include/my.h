/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#include "defender.h"

int my_getnbr(char *str);
char *my_realloc(char *string, int newsize);
char *my_strncat(char *dest, char *source, int n);
char *my_strncpy(char *dest, char *source, int n);
char *my_strcat(char *dest, char *source);
char *my_strcpy(char *dest, char *source);
char *my_strdup(char *string);
char *my_strcat(char *dest, char *source);
int my_strcmp(char *string1, char *string2);
int my_strncmp(char *str1, char *str2, int length);
int my_nbrlen(long n);
int my_putstr(char const *str);
int my_put_nbr(long nbr);
void my_putchar(char c);
void my_putchar_err(char c);
int my_strlen(char *c);
void my_printf(char *str, ...);
int my_count_words(char *str);
int is_char_alpha(char a);
int my_atoi(char *str);
char *read_file(char const *filepath);
int how_many_words(char *string, char delim);
int how_m_ch(char *string, int index, char delim);
char **my_str_to_word(char *string, char delim);
/* the game */
void main_loop(defender *game);

//initalizing
areas *linked(void);
int init_game(defender *game);
void init_sprites(defender *game);
enemy *link_enm(void);

//running
void start_game(defender *game);
void in_game(defender *game);

//events
void manage_start_game(defender *game);
void manage_in_game_events(defender *game);

//draw
void draw_bg(defender *game);
void draw_flying_tower(defender *game);
void display_towers(defender *game);
void draw_enm(defender *game);
void move_enm(defender *game, enemy *alive, sfVector2f v);
void shooting(defender *game);
void draw_fire(enemy *enm_head, areas *twr_head, defender *game);
//tools
void init_areas(areas *link);
void check_infloor(defender *game);
void set_pos(defender *game);
void animat_enm(defender *game);
int shoot_range(enemy *head, areas *twr_head);
int find_difference(float a, float b);
#endif
