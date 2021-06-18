/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init2
*/

#include "my_rpg.h"

void init_music(st_scene *scene)
{
    scene->music = sfMusic_createFromFile("assets/music/game.ogg");
}

void init_intro(st_scene *scene, int i, char **tab)
{
    scene->intro = malloc(sizeof(object) * 2);
    scene->intro[0] = new_sprite(tab[i+2]);
    scene->intro[0]->clock = sfClock_create();
    scene->intro[0]->pos.x = my_getnbr(tab[i+3]);
    scene->intro[0]->pos.y = my_getnbr(tab[i+4]);
    scene->intro[0]->rect.left = my_getnbr(tab[i+5]);
    scene->intro[0]->rect.top = my_getnbr(tab[i+6]);
    scene->intro[0]->rect.width = my_getnbr(tab[i+7]);
    scene->intro[0]->rect.height = my_getnbr(tab[i+8]);
    scene->intro[1] = NULL;
}

void init_portal(st_scene *scene, int i, char **tab)
{
    scene->portal = malloc(sizeof(object) * 2);
    scene->portal[0] = new_sprite(tab[i+2]);
    scene->portal[0]->clock = sfClock_create();
    scene->portal[0]->pos.x = my_getnbr(tab[i+3]);
    scene->portal[0]->pos.y = my_getnbr(tab[i+4]);
    scene->portal[0]->rect.left = my_getnbr(tab[i+5]);
    scene->portal[0]->rect.top = my_getnbr(tab[i+6]);
    scene->portal[0]->rect.width = my_getnbr(tab[i+7]);
    scene->portal[0]->rect.height = my_getnbr(tab[i+8]);
    scene->portal[1] = NULL;
    scene->portal[0]->clock = sfClock_create();
}

int init_game(st_scene *scene, char **tab)
{
    scene->state = my_getnbr(tab[146]+6);
    scene->xp = my_getnbr(tab[145]+3);
    scene->difficulty = my_getnbr(tab[147]+11);
    scene->background_index = my_getnbr(tab[148]+17);
    scene->nb_dial_c = my_getnbr(tab[149]+10);
    scene->nb_dial_f = my_getnbr(tab[150]+10);
    scene->old_state = my_getnbr(tab[151]+10);
    scene->win = 0;
    scene->nb_dial_f = 0;
    scene->nb_dial_c = 0;
}