/*
** EPITECH PROJECT, 2021
** event_managment.c
** File description:
** manage events
*/

#include "../include/my.h"
#include "../include/defender.h"

void manage_start_game(defender *game)
{
    sfEvent event;
    sfSprite *sprite;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if ((event.mouseMove.x > 307) && (event.mouseMove.x < 1084) &&
            (event.mouseMove.y > 622) && (event.mouseMove.y < 787)) {
                sprite = game->start_game_cpy;
        } else {
            sprite = game->start_game;
        }
        if ((event.mouseButton.button == sfMouseLeft) &&
            (event.mouseButton.x > 307) && (event.mouseButton.x < 1084) &&
            (event.mouseButton.y > 622) && (event.mouseButton.y < 787))  {
                game->state = 1;
            }
            sfRenderWindow_drawSprite(game->window, sprite, NULL);
    }
}

void manage_in_game_events(defender *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(game->window);
            exit(0);
        }
    }
}