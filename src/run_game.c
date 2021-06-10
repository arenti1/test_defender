/*
** EPITECH PROJECT, 2021
** run_game.c
** File description:
** startgame, ingame and end game
*/

#include "../include/my.h"
#include "../include/defender.h"

void start_game(defender *game)
{
    manage_start_game(game);
}

void in_game(defender *game)
{
    manage_in_game_events(game);
    draw_bg(game);
    draw_flying_tower(game);
    draw_towers(game);
    draw_enemy(game);
    shooting(game);
    sfRenderWindow_display(game->window);
}