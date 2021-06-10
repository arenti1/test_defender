/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** defender
*/

#include "../include/my.h"
#include "../include/defender.h"

void main_loop(defender *game)
{
        while (sfRenderWindow_isOpen(game->window)) {
            if (game->state == 0) {
                start_game(game);
            } else if (game->state == 1)
            {
                in_game(game);
            }
            sfRenderWindow_display(game->window);
        }

}

int main(void)
{
    defender game;

    init_game(&game);
    main_loop(&game);
}