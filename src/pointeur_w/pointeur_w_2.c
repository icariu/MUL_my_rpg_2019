/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pointeur_w_2
*/

#include "my_rpg.h"

void if_six_w(st_scene *scene, sfRenderWindow *window)
{
    sfSprite_setPosition(scene->player->spr, scene->player->pos);
    sfRenderWindow_drawSprite(window, scene->back[2]->spr, NULL);
    sfRenderWindow_drawSprite(window, scene->player->spr, NULL);
    craftman_dialog(window, scene);
    scene->background_index = 2;
}