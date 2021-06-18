/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound
*/

#include "my_rpg.h"

void sound_gestion(st_scene *scene)
{
    sfMusic_setVolume(scene->music, 1);
    sfMusic_play(scene->music);
    sfMusic_setLoop(scene->music, sfTrue);
}