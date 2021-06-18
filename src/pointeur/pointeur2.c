/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pointeur2
*/

#include "my_rpg.h"

void if_six(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    move_player(scene, event);
    if (event.type == sfEvtMouseButtonReleased && event.key.code == sfMouseLeft)
        scene->nb_dial_c++;
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyS && scene->player->pos.y == 550 &&
    scene->player->pos.x <= 450 && scene->player->pos.x >= 370) {
        scene->state = 1;
        scene->player->pos.x = 360;
        scene->player->pos.y = 210;
    }
}

void if_seven(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    main_menu(scene, window, event);
}

void if_eight(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    inventory_menu(scene, window, event);
}

void if_nine(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    display_shop(scene, window, event, scene->background_index);
}

void if_ten(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    settings_menu(scene, window, event);
}