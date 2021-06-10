/*
** EPITECH PROJECT, 2021
** tools2.c
** File description:
** tools number 2
*/

#include "../include/my.h"
#include "../include/defender.h"

void free_enemy(enemy *e)
{
    enemy *temp;
    temp = e;
    while (e != NULL){
        temp = e->next;
        free(e);
        e = temp;
    }
}

void free_towers(areas *a)
{
    areas *temp;
    temp = a;
    while (a != NULL){
        temp = a->next;
        free(a);
        a = temp;
    }
}

void free_game(defender *game)
{
    free_towers(game->list);
    free_enemy(game->enm);
    
    sfTexture_destroy(game->fire_t);
    sfTexture_destroy(game->tower_bt);
    sfTexture_destroy(game->tower_rt);
    sfTexture_destroy(game->back_lt);
    sfTexture_destroy(game->back_rt);
    sfTexture_destroy(game->back_t);
    sfTexture_destroy(game->front_lt);
    
    sfTexture_destroy(game->front_rt);
    sfTexture_destroy(game->front_t);
    sfTexture_destroy(game->side_t);
    sfTexture_destroy(game->side_lt);
    sfTexture_destroy(game->side_rt);
    /*
    sfTexture_destroy(game->fire_t);
    sfTexture_destroy(game->earth_t);
*/
    sfSprite_destroy(game->start_game);
    sfSprite_destroy(game->start_game_cpy);
    sfSprite_destroy(game->back);
    sfSprite_destroy(game->back_l);
    sfSprite_destroy(game->back_r);
    sfSprite_destroy(game->front);
    sfSprite_destroy(game->front_l);
    sfSprite_destroy(game->front_r);
    sfSprite_destroy(game->side);
    sfSprite_destroy(game->side_l);
    sfSprite_destroy(game->side_r);
    sfSprite_destroy(game->tower_bs);
    sfSprite_destroy(game->tower_rs);
    sfSprite_destroy(game->fire);
    sfSprite_destroy(game->earth);
}

int find_difference(float a, float b)       
{//DIFFERENCE BETWEEN TWO NUMBERS
    if (a < b){
        return b - a;
    }
    else {
        return a - b;
    }
}