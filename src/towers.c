/*
** EPITECH PROJECT, 2021
** draw.c
** File description:
** drawing in game
*/

#include "../include/defender.h"
#include "../include/my.h"

void draw_bg(defender *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
}

void draw_flying_tower(defender *game)
{
    sfVector2f v;
    sfVector2f b;

    if ((game->event.mouseButton.button == sfMouseLeft) &&
    (game->event.mouseButton.x > 1288) && (game->event.mouseButton.x < 1339) &&
    (game->event.mouseButton.y > 54) && (game->event.mouseButton.y < 154)) {
        game->t_switch = 1;
    }
    if ((game->event.mouseButton.button == sfMouseLeft) &&
    (game->event.mouseButton.x > 1380) && (game->event.mouseButton.x < 1430) &&
    (game->event.mouseButton.y > 54) && (game->event.mouseButton.y < 154)) {
        game->t_switch = 2;
    }
    if (game->event.type == sfEvtMouseButtonReleased) {
        check_infloor(game);
            game->t_switch = 0;
    }
    if (game->t_switch != 1) {
        v.x = 1288;
        v.y = 54;
        sfSprite_setPosition(game->tower_bs, v);
        sfRenderWindow_drawSprite(game->window, game->tower_bs, NULL);
        }
    if (game->t_switch != 2){
        b.x = 1380;
        b.y = 54;
        sfSprite_setPosition(game->tower_rs, b);
        sfRenderWindow_drawSprite(game->window, game->tower_rs, NULL);
    }
    if (game->t_switch == 1) {
        v.x = sfMouse_getPositionRenderWindow(game->window).x - 10;
        v.y = sfMouse_getPositionRenderWindow(game->window).y - 10;
        sfSprite_setPosition(game->tower_bs, v);
        sfRenderWindow_drawSprite(game->window, game->tower_bs, NULL);
        }
    else if (game->t_switch == 2) {
        b.x = sfMouse_getPositionRenderWindow(game->window).x - 10;
        b.y = sfMouse_getPositionRenderWindow(game->window).y - 10;
        sfSprite_setPosition(game->tower_rs, b);
        sfRenderWindow_drawSprite(game->window, game->tower_rs, NULL);
    }
    
}

void draw_towers(defender *game)
{
    areas *head = game->list;
    sfVector2f v;
    while (head != NULL) {
        if (head->busy == 1) {
            v.x = head->min_x;
            v.y = head->min_y;
            sfSprite_setPosition(head->tower, v);
            sfRenderWindow_drawSprite(game->window, head->tower, NULL);
        }
        head = head->next;
    }
}



