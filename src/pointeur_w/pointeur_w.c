/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pointeur_w
*/

#include "my_rpg.h"

void if_one_w(st_scene *scene, sfRenderWindow *window)
{
    sfVector2f pos = {-40, 250};

    sfSprite_setPosition(scene->player->spr, scene->player->pos);
    sfRenderWindow_drawSprite(window, scene->back[0]->spr, NULL);
    portal(scene, window, pos);
    sfRenderWindow_drawSprite(window, scene->player->spr, NULL);
    first_dialog(window, scene);
    scene->background_index = 0;
}

void if_two_w(st_scene *scene, sfRenderWindow *window)
{
    sfVector2f pos = {300, -40};

    sfSprite_setPosition(scene->player->spr, scene->player->pos);
    sfRenderWindow_drawSprite(window, scene->back[3]->spr, NULL);
    display_enemies(scene, window);
    portal(scene, window, pos);
    sfRenderWindow_drawSprite(window, scene->player->spr, NULL);
    particles_draw(scene->rain, window, scene->rain_clock);
    scene->background_index = 3;
}

void if_three_w(st_scene *scene, sfRenderWindow *window)
{
    sfVector2f pos = {360, -40};

    sfSprite_setPosition(scene->player->spr, scene->player->pos);
    sfRenderWindow_drawSprite(window, scene->back[1]->spr, NULL);
    display_enemies(scene, window);
    portal(scene, window, pos);
    sfRenderWindow_drawSprite(window, scene->player->spr, NULL);
    scene->background_index = 1;
}

void if_four_w(st_scene *scene, sfRenderWindow *window)
{
    sfVector2f pos = {765, 230};

    sfSprite_setPosition(scene->player->spr, scene->player->pos);
    sfRenderWindow_drawSprite(window, scene->back[5]->spr, NULL);
    display_enemies(scene, window);
    portal(scene, window, pos);
    sfRenderWindow_drawSprite(window, scene->player->spr, NULL);
    particles_draw(scene->snow, window, scene->rain_clock);
    scene->background_index = 5;
}

void if_five_w(st_scene *scene, sfRenderWindow *window)
{
    if (scene->player->pos.x >= 120 && scene->player->pos.x <= 220
    && scene->player->pos.y >= 0 && scene->player->pos.y <= 188) {
        scene->state = 13;
        scene->win = 1;
    }
    sfSprite_setPosition(scene->player->spr, scene->player->pos);
    sfRenderWindow_drawSprite(window, scene->back[4]->spr, NULL);
    display_enemies(scene, window);
    sfRenderWindow_drawSprite(window, scene->player->spr, NULL);
    sfRenderWindow_drawSprite(window, scene->princess->spr, NULL);
    scene->background_index = 4;
}