/*
** EPITECH PROJECT, 2021
** tools.c
** File description:
** tools
*/

#include "../include/my.h"
#include "../include/defender.h"

void init_areas(areas *link)
{
    if (link->N == 0) {
        link->min_x = 200;
        link->max_x = 270;
        link->min_y = 626;
        link->max_y = 674;
    }
    else if (link->N == 1) {
        link->min_x = 399;
        link->max_x = 477;
        link->min_y = 317;
        link->max_y = 372;
    }
    else if (link->N == 2) {
        link->min_x = 624;
        link->max_x = 699;
        link->min_y = 480;
        link->max_y = 575;
    }
    else if (link->N == 3) {
        link->min_x = 882;
        link->max_x = 963;
        link->min_y = 711;
        link->max_y = 776;
    }
    else if (link->N == 4) {
        link->min_x = 1046;
        link->max_x = 1124;
        link->min_y = 280;
        link->max_y = 387;
    }
    else if (link->N == 5) {
        link->min_x = 1344;
        link->max_x = 1422;
        link->min_y = 518;
        link->max_y = 580;
    }
}

void check_infloor(defender *game)
{
    areas *head = game->list;

    while (head != NULL){
    if ((head->N == 0) && (game->event.mouseButton.x > 200) &&
        (game->event.mouseButton.x < 270) &&
        (game->event.mouseButton.y > 626) &&
        (game->event.mouseButton.y < 674)) {
            head->busy = 1;
            if (game->t_switch == 1){
                head->tower = game->tower_bs;
                head->type = 1;
            }
            else if (game->t_switch == 2){
                head->tower = game->tower_rs;
                head->type = 2;
            }
        }
    else if ((head->N == 1) && (game->event.mouseButton.x > 399) &&
        (game->event.mouseButton.x < 477) &&
        (game->event.mouseButton.y > 317) &&
        (game->event.mouseButton.y < 372)) {
            head->busy = 1;
            if (game->t_switch == 1){
                head->tower = game->tower_bs;
                head->type = 1;
            }
            else if (game->t_switch == 2){
                head->tower = game->tower_rs;
                head->type = 2;
            }
        }
    else if ((head->N == 2) && (game->event.mouseButton.x > 624) &&
        (game->event.mouseButton.x < 699) &&
        (game->event.mouseButton.y > 480) &&
        (game->event.mouseButton.y < 575)) {
            head->busy = 1;
            if (game->t_switch == 1){
                head->tower = game->tower_bs;
                head->type = 1;
            }
            else if (game->t_switch == 2){
                head->tower = game->tower_rs;
                head->type = 2;
            }
        }
    else if ((head->N == 3) && (game->event.mouseButton.x > 882) &&
        (game->event.mouseButton.x < 963) &&
        (game->event.mouseButton.y > 711) &&
        (game->event.mouseButton.y < 776)) {
            head->busy = 1;
            if (game->t_switch == 1) {
                head->tower = game->tower_bs;
                head->type = 1;
            }
            else if (game->t_switch == 2){
                head->tower = game->tower_rs;
                head->type = 2;
            }
        }
    else if ((head->N == 4) && (game->event.mouseButton.x > 1046) &&
        (game->event.mouseButton.x < 1124) &&
        (game->event.mouseButton.y > 280) &&
        (game->event.mouseButton.y < 387)) {
            head->busy = 1;
            if (game->t_switch == 1){
                head->tower = game->tower_bs;
                head->type = 1;
            }
            else if (game->t_switch == 2){
                head->tower = game->tower_rs;
                head->type = 2;
            }
        }
    else if ((head->N == 5) && (game->event.mouseButton.x > 1344) &&
        (game->event.mouseButton.x < 1422) &&
        (game->event.mouseButton.y > 518) &&
        (game->event.mouseButton.y < 580)) {
            head->busy = 1;
            if (game->t_switch == 1){
                head->tower = game->tower_bs;
                head->type = 1;
            }
            else if (game->t_switch == 2){
                head->tower = game->tower_rs;
                head->type = 2;
            }
        }
    head = head->next;
    }
}

void animat_enm(defender *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    float a = sfTime_asSeconds(game->time);

    if (a > 0.15) {
        game->enm_animation = game->enm_animation == 2 ? 0 \
        : game->enm_animation + 1; 
        sfClock_restart(game->clock);
    }
}