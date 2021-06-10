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
/*
int shoot_range(enemy *head, areas *twr_head)
{
    float radious = 170.0;
    float distance = sqrt(pow((head->pos.x - twr_head->min_x), 2)
    + pow((head->pos.y - twr_head->min_y), 2));

    //printf("distance->%f\n", distance);

    if (distance <= radious){
        return (1);
    } else {
        return (-1);
    }
}
*/
/*
void draw_fire(enemy *enm_head, areas *twr_head, defender *game)
{
    int speed = 1;
    int damage = 20;

    if (enm_head->pos.x >= (twr_head->min_x + 10))
    {
        if (find_difference(enm_head->pos.x, twr_head->shot.x) > 2){
            enm_head->health -= damage;
            twr_head->shot.x = twr_head->min_x + 5;
            twr_head->shot.y = twr_head->min_y + 5;
        } else {
            twr_head->shot.x += speed;
        }
    }
    else if (enm_head->pos.x <= (twr_head->min_x + 10))
    {
        if (find_difference(enm_head->pos.x, twr_head->shot.x) > 2){
            enm_head->health -= damage;

            twr_head->shot.x = twr_head->min_x + 5;
            twr_head->shot.y = twr_head->min_y + 5;
        } else {
            twr_head->shot.x -= speed;
        }
    }
    if (enm_head->pos.y >= (twr_head->min_y + 10))
    {
        if (find_difference(enm_head->pos.x, twr_head->shot.x) > 2){
            enm_head->health -= damage;
            twr_head->shot.x = twr_head->min_x + 5;
            twr_head->shot.y = twr_head->min_y + 5;
        } else {
            twr_head->shot.y += speed;
        }
    }
    else if (enm_head->pos.y <= (twr_head->min_y + 10))
    {
        if (find_difference(enm_head->pos.x, twr_head->shot.x) > 2){
            enm_head->health -= damage;
            twr_head->shot.x = twr_head->min_x + 5;
            twr_head->shot.y = twr_head->min_y + 5;
        } else {
            twr_head->shot.y -= speed;
        }
    }
    sfSprite_setPosition(game->fire, twr_head->shot);
    sfRenderWindow_drawSprite(game->window, game->fire, NULL);
}
*/
