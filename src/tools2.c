/*
** EPITECH PROJECT, 2021
** tools2.c
** File description:
** tools number 2
*/

#include "../include/my.h"
#include "../include/defender.h"

void move_enm(defender *game, enemy *alive, sfVector2f v)
{
    sfSprite *pick;
    if (game->dir == 0) {
        if (game->enm_animation == 0) {
            pick = game->side;
        }
        else if (game->enm_animation == 1) {
            pick = game->side_r;
        }
        else {
            pick = game->side_l;
        }
    }
    else if (game->dir == 1) {
        if (game->enm_animation == 0) {
            pick = game->front;
        }
        else if (game->enm_animation == 1) {
            pick = game->front_r;
        }
        else {
            pick = game->front_l;
        }
    }
    else {
        if (game->enm_animation == 0) {
            pick = game->back;
        }
        else if (game->enm_animation == 1) {
            pick = game->back_r;
        }
        else {
            pick = game->back_l;
        }
    }
    if (alive->health > 0) {
        animat_enm(game);
        sfSprite_setPosition(pick, v);
        sfRenderWindow_drawSprite(game->window, pick, NULL);
    }
}

void shooting(defender *game)
{
    enemy *enm_head = game->enm;
    areas *twr_head = game->list;
    int a;
    int i = 1;
    while (twr_head != NULL){
        enm_head = game->enm;
        while (enm_head != NULL){
            a = shoot_range(enm_head, twr_head);
            if (a == 1 && i == 1 && twr_head->busy == 1) {
                    draw_fire(enm_head, twr_head, game);
                    i--;
                }
            enm_head = enm_head->next;
        }

        i = 1;
        twr_head = twr_head->next;
    }
    printf("%d\n", a);
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