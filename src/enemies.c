/*
** EPITECH PROJECT, 2021
** enemies.c
** File description:
** tools
*/

#include "../include/my.h"
#include "../include/defender.h"

void draw_enemy(defender *game)
{
    enemy *head = game->enm;
    float speed = 3;

    while (head != NULL) {
        if (head->pos.x < 210) {
            head->pos.x += speed;
            game->dir = 0;
        }
        else if ((head->pos.x < 215) && (head->pos.y > 201)) {
            head->pos.y -= speed;
            game->dir = 2;
        }
        else if (head->pos.x < 500) {
            head->pos.x += speed;
            game->dir = 0;
        }
        else if ((head->pos.x > 505) && (head->pos.y < 610)
        && (head->pos.x < 900)) {
            head->pos.y += speed;
            game->dir = 1;
        }
        else if (head->pos.x < 900) {
            head->pos.x += speed;
            game->dir = 0;
        }
        else if ((head->pos.x < 905) && (head->pos.y > 405)
        && (head->pos.x > 899)){
            head->pos.y -= speed;
            game->dir = 2;
        }
        else if (head->pos.x < 1500) {
            head->pos.x += speed;
            game->dir = 0;
        }
        move_enemy(game, head, head->pos);
        head = head->next;
    }
}

void move_enemy(defender *game, enemy *alive, sfVector2f v)
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