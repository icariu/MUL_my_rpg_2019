/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_player
*/

#include "my_rpg.h"

void move_player_next(st_scene *scene, sfEvent event)
{
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyS && scene->player->pos.y <= 540)
        if (collision_check(scene->player, 0, 10, scene->state)) {
            scene->player->rect.top = 0;
            scene->player->rect.left == 140 ? (scene->player->rect.left = 240)
            : (scene->player->rect.left = 140);
        }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyZ && scene->player->pos.y >= 0)
        if (collision_check(scene->player, 0, -10, scene->state)) {
            scene->player->rect.top = 145;
            scene->player->rect.left == 140 ? (scene->player->rect.left = 240)
            : (scene->player->rect.left = 140);
        }
    sfSprite_setTextureRect(scene->player->spr, scene->player->rect);
}

void move_player(st_scene *scene, sfEvent event)
{
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyQ && scene->player->pos.x != 0)
        if (collision_check(scene->player, -10, 0, scene->state)) {
            scene->player->rect.top = 48;
            scene->player->rect.left == 140 ? (scene->player->rect.left = 240)
            : (scene->player->rect.left = 140);
        }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyD && scene->player->pos.x != 750)
        if (collision_check(scene->player, 10, 0, scene->state)) {
            scene->player->rect.top = 97;
            scene->player->rect.left == 140 ? (scene->player->rect.left = 240)
            : (scene->player->rect.left = 140);
        }
    move_player_next(scene, event);
}