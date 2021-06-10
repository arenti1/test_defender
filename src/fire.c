/*
** EPITECH PROJECT, 2021
** fire.c
** File description:
** drawing in game
*/

#include "../include/defender.h"
#include "../include/my.h"

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
            if (a == 1 && i == 1 && twr_head->busy == 1 && enm_head->health > 0) {
                    draw_fire(enm_head, twr_head, game);
                    i--;
                }
            enm_head = enm_head->next;
        }

        i = 1;
        twr_head = twr_head->next;
    }
}

void draw_fire(enemy *e, areas *twr, defender *game)
{
    if (find_difference(e->pos.x, twr->shot.x) > 4 || find_difference(e->pos.y, twr->shot.y) > 4){
        if (e->pos.x < twr->shot.x){
            twr->shot.x -= 5;
        }
        else {
            twr->shot.x += 5;
        }
        if (e->pos.y < twr->shot.y){
            twr->shot.y -= 5;
        }
        else {
            twr->shot.y += 5;
        }
        
        sfSprite_setPosition(game->fire, twr->shot);
        sfRenderWindow_drawSprite(game->window, game->fire, NULL);

    }
    else {
        twr->shot.x = twr->min_x;
        twr->shot.y = twr->min_y;
        e->health -= 20;
    }
    if (twr->type == 2){
        sfSprite_setPosition(game->fire, twr->shot);
        sfRenderWindow_drawSprite(game->window, game->fire, NULL);
    }
    else {
        sfSprite_setPosition(game->earth, twr->shot);
        sfRenderWindow_drawSprite(game->window, game->earth, NULL);
    }
}

int shoot_range(enemy *head, areas *twr_head)
{
    int rad = 170;
    int r = pow(rad, 2);
    if ((pow(head->pos.x - twr_head->min_x, 2) + pow(head->pos.y - twr_head->min_y, 2)) < r){
        return 1;
    }
    return 0;
}