/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** intro
*/

#include "my_rpg.h"

void display_intro(st_scene *scene, sfRenderWindow *window)
{
    sfTime time = sfSeconds(0.05);
    sfIntRect rect = scene->intro[0]->rect;

    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTextureRect(scene->intro[0]->spr, scene->intro[0]->rect);
        sfRenderWindow_drawSprite(window, scene->intro[0]->spr, NULL);
        rect = scene->intro[0]->rect;
        if (rect.left >= 15200 && rect.top < 1800) {
            scene->intro[0]->rect.top += 600;
            scene->intro[0]->rect.left = 0;
        }
        if (rect.left >= 8800 && rect.top >= 1800)
            break;
        scene->intro[0]->rect.left += 800;
        sfSleep(time);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}