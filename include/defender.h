/*
** EPITECH PROJECT, 2021
** defender.h
** File description:
** library defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>

typedef struct areas
{
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    int N;
    sfSprite *tower;
    short busy;
    short type;
    sfVector2f shot;
    struct areas *next;
} areas ;


typedef struct enemy {
    sfVector2f pos;
    int health;
    sfSprite *enm;

    struct enemy *next;

} enemy;

typedef struct defender
{
    sfRenderWindow *window;
    sfVideoMode video;
    sfTexture *main_map;
    sfSprite *background;
    sfEvent event;
    sfSprite *start_game;
    sfSprite *start_game_cpy;
    sfTexture *tower_bt;
    sfTexture *tower_rt;
    sfTexture *back_t;
    sfSprite *back;
    sfTexture *back_lt;
    sfSprite *back_l;
    sfTexture *back_rt;
    sfSprite *back_r;
    sfTexture *front_lt;
    sfSprite *front_l;
    sfTexture *front_rt;
    sfSprite *front_r;
    sfTexture *front_t;
    sfSprite *front;
    sfTexture *side_lt;
    sfSprite *side_l;
    sfTexture *side_rt;
    sfSprite *side_r;
    sfTexture *side_t;
    sfSprite *side;
    sfSprite *tower_bs;
    sfSprite *tower_rs;
    sfTexture *fire_t;
    sfSprite *fire;
    sfTexture *earth_t;
    sfSprite *earth;
    sfClock *clock;
    sfTime time;
    areas *list;
    enemy *enm;
    short dir;
    short t_switch;
    short enm_animation;
    short state;
} defender;

#endif /* defender */
