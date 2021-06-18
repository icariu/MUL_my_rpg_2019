/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** portal
*/

#include "my_rpg.h"

void portal(st_scene *scene, sfRenderWindow *window, sfVector2f pos)
{
    sfTime time = sfClock_getElapsedTime(scene->portal[0]->clock);
    float second = (float) time.microseconds / 1000000.0;

    if (second > 0.05) {
        scene->portal[0]->rect.top += 70;
        if (scene->portal[0]->rect.top == 630)
            scene->portal[0]->rect.top = 0;
        sfClock_restart(scene->portal[0]->clock);
    }
    display_sprite(scene->portal[0]->spr, window,
    pos, scene->portal[0]->rect);
}