/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pointeur
*/

#include "my_rpg.h"

void if_one(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    move_player(scene, event);
    if (event.type == sfEvtMouseButtonReleased && event.key.code == sfMouseLeft)
        scene->nb_dial_f++;
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyQ && scene->player->pos.x == 0 &&
    scene->player->pos.y <= 318 && scene->player->pos.y >= 240) {
        scene->state++;
        scene->player->pos.x = 750;
        scene->player->pos.y = 330;
    }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyZ && scene->player->pos.y <= 210 &&
    scene->player->pos.x <= 390 && scene->player->pos.x >= 360) {
        scene->state = 6;
        scene->player->pos.x = 400;
        scene->player->pos.y = 550;
    }
}

void if_two(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    move_player(scene, event);
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyZ && scene->player->pos.y <= 0 &&
    scene->player->pos.x <= 335 && scene->player->pos.x >= 295) {
        scene->state++;
        scene->player->pos.x = 660;
        scene->player->pos.y = 550;
    }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyD && scene->player->pos.x == 750 &&
    scene->player->pos.y <= 380 && scene->player->pos.y >= 280) {
        scene->state--;
        scene->player->pos.x = 0;
        scene->player->pos.y = 260;
    }
}

void if_three(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    move_player(scene, event);
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyZ && scene->player->pos.y <= 0 &&
    scene->player->pos.x <= 415 && scene->player->pos.x >= 365) {
        scene->state++;
        scene->player->pos.x = 0;
        scene->player->pos.y = 270;
    }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyS && scene->player->pos.y == 550 &&
    scene->player->pos.x <= 660 && scene->player->pos.x >= 650) {
        scene->state--;
        scene->player->pos.x = 320;
        scene->player->pos.y = 0;
    }
}

void if_four(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    move_player(scene, event);
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyD && scene->player->pos.x == 750 &&
    scene->player->pos.y <= 240 && scene->player->pos.y >= 220) {
        scene->state++;
        scene->player->pos.x = 140;
        scene->player->pos.y = 550;
    }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyQ && scene->player->pos.x == 0 &&
    scene->player->pos.y <= 330 && scene->player->pos.y >= 260) {
        scene->state--;
        scene->player->pos.x = 370;
        scene->player->pos.y = 0;
    }
}

void if_five(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    move_player(scene, event);
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyS && scene->player->pos.y == 550 &&
    scene->player->pos.x <= 300 && scene->player->pos.x >= 120) {
        scene->state--;
        scene->player->pos.x = 750;
        scene->player->pos.y = 230;
    }
}