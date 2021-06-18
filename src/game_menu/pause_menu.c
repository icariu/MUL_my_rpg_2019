/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu
*/

#include "my_rpg.h"

void display_pause_menu(st_scene *scene, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, scene->menu[0]->spr, NULL);
    draw_button(scene, "  MENU", scene->button[0]->pos, 0);
    draw_button(scene, "  QUIT", scene->button[1]->pos, 1);
    button_hover(scene, scene->button[0]->pos, 0, 7);
    button_hover(scene, scene->button[1]->pos, 1, 0);
}