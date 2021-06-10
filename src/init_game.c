/*
** EPITECH PROJECT, 2021
** init_game.c
** File description:
** initalize the game
*/

#include "../include/my.h"
#include "../include/defender.h"

enemy *link_enm(void)
{
    int i = 0;
    enemy *tmp;
    enemy *head = (enemy *) malloc(sizeof(enemy));
    head->pos.x = 0;
    head->pos.y = 515;
    head->health = 100;
    int a = -70;
    tmp = head;
    while (i <= 4) {
        tmp->next = (enemy *) malloc(sizeof(enemy));
        tmp = tmp->next;
        tmp->pos.x = a;
        tmp->pos.y = 525;
        tmp->health = 100;
        a -= 70;
        i++;
    }
    tmp->next = NULL;
    return head;
}

areas *linked(void)
{
    int i = 0;
    areas *temp;
    areas *head = (areas *) malloc(sizeof(areas));
    head->N = i;
    head->busy = 0;
    init_areas(head);
    head->shot.x = head->min_x + 5;
    head->shot.y = head->min_y + 5;
    temp = head;
    while (i <= 5){
        temp->next = (areas *) malloc(sizeof(areas));
        temp = temp->next;
        temp->N = i + 1;
        temp->busy = 0;
        init_areas(temp);
        temp->shot.x = temp->min_x + 5;
        temp->shot.y = temp->min_y + 5;
        i++;
    }
    temp->next = NULL;
    return head;
}

void init_sprites(defender *game)
{
    sfTexture *start_game =
        sfTexture_createFromFile("./rec/castle01.png", NULL);
    sfTexture *start_game_cpy =
        sfTexture_createFromFile("./rec/castle02.png", NULL);

    game->start_game = sfSprite_create();
    sfSprite_setTexture(game->start_game, start_game, sfTrue);
    game->start_game_cpy = sfSprite_create();
    sfSprite_setTexture(game->start_game_cpy, start_game_cpy, sfTrue);
    game->tower_bt = sfTexture_createFromFile("./rec/towers/black.png", NULL);
    game->tower_bs = sfSprite_create();
    sfSprite_setTexture(game->tower_bs, game->tower_bt, sfTrue);
    game->tower_rt = sfTexture_createFromFile("./rec/towers/fire.png", NULL);
    game->tower_rs = sfSprite_create();
    sfSprite_setTexture(game->tower_rs, game->tower_rt, sfTrue);
    game->main_map = sfTexture_createFromFile("./rec/testmap.png", NULL);
    game->background = sfSprite_create();

    game->fire_t = sfTexture_createFromFile("./rec/shootin/fires.jpeg", NULL);
    game->fire = sfSprite_create();
    sfSprite_setTexture(game->fire, game->fire_t, sfTrue);

    game->earth_t = sfTexture_createFromFile("./rec/shootin/earth.png", NULL);
    game->earth = sfSprite_create();
    sfSprite_setTexture(game->earth, game->earth_t, sfTrue);

    game->back_t = sfTexture_createFromFile("./rec/enemys/back.png", NULL);
    game->back = sfSprite_create();
    sfSprite_setTexture(game->back, game->back_t, sfTrue);

    game->back_lt = sfTexture_createFromFile("./rec/enemys/backl.png", NULL);
    game->back_l = sfSprite_create();
    sfSprite_setTexture(game->back_l, game->back_lt, sfTrue);

    game->back_rt = sfTexture_createFromFile("./rec/enemys/backr.png", NULL);
    game->back_r = sfSprite_create();
    sfSprite_setTexture(game->back_r, game->back_rt, sfTrue);

    game->front_t = sfTexture_createFromFile("./rec/enemys/front.png", NULL);
    game->front = sfSprite_create();
    sfSprite_setTexture(game->front, game->front_t, sfTrue);

    game->front_lt = sfTexture_createFromFile("./rec/enemys/front_l.png", NULL);
    game->front_l = sfSprite_create();
    sfSprite_setTexture(game->front_l, game->front_lt, sfTrue);

    game->front_rt = sfTexture_createFromFile("./rec/enemys/front_r.png", NULL);
    game->front_r = sfSprite_create();
    sfSprite_setTexture(game->front_r, game->front_rt, sfTrue);

    game->side_t = sfTexture_createFromFile("./rec/enemys/side.png", NULL);
    game->side = sfSprite_create();
    sfSprite_setTexture(game->side, game->side_t, sfTrue);

    game->side_lt = sfTexture_createFromFile("./rec/enemys/side_l.png", NULL);
    game->side_l = sfSprite_create();
    sfSprite_setTexture(game->side_l, game->side_lt, sfTrue);

    game->side_rt = sfTexture_createFromFile("./rec/enemys/side_r.png", NULL);
    game->side_r = sfSprite_create();
    sfSprite_setTexture(game->side_r, game->side_rt, sfTrue);

    sfSprite_setTexture(game->background, game->main_map, sfTrue);
}

int init_game(defender *game)
{
    areas *head;
    sfVideoMode video = {1500, 1000, 32};

    game->video = video;
    game->window = sfRenderWindow_create(game->video, "map", sfTitlebar |
        sfClose, NULL);
    game->state = 0;
    game->t_switch = 0;
    game->enm_animation = 0;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    init_sprites(game);
    game->list = linked();
    game->enm = link_enm();
    game->clock = sfClock_create();
}