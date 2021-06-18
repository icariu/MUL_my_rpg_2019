/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** overlay
*/

#include "my_rpg.h"

void overlay(st_scene *scene, sfRenderWindow *window)
{
    if (scene->state < 7)
        sfRenderWindow_drawSprite(window, scene->overlay[0]->spr, NULL);
}