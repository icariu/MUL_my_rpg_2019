/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display
*/

#include "my_rpg.h"

void move_mobs(st_scene *scene, st_foes *tmp, int start, int end)
{
    sfTime time = sfClock_getElapsedTime(scene->mobs_clock);
    int timer = sfTime_asMilliseconds(time);

    if (timer % 600 == 0) {
        for (start; tmp != NULL && start < end; tmp = tmp->next, start++) {
            if (tmp->pos.x > scene->player->pos.x)
                tmp->pos.x -= 10;
            else
                tmp->pos.x += 10;
            if (tmp->pos.y > scene->player->pos.y)
                tmp->pos.y -= 10;
            else
                tmp->pos.y += 10;
        }
    } else
        return;
}

void display_loop(sfRenderWindow *window, st_foes *tmp, int limit, int i)
{
    for (i; tmp != NULL && i < limit; tmp = tmp->next, i++)
        if (tmp->life > 0) {
            sfSprite_setPosition(tmp->spr, tmp->pos);
            sfRenderWindow_drawSprite(window, tmp->spr, NULL);
        }
}

void display_enemies(st_scene *scene, sfRenderWindow *window)
{
    st_foes *tmp = scene->control->tail;
    int limit = 0, i = 0;

    if (scene->state == 2) {
        tmp = scene->control->tail;
        limit = 2;
    } else if (scene->state == 3) {
        for (i = 0; i < 2; i++)
            tmp = tmp->next;
        limit = 4;
    } if (scene->state == 4) {
        for (i = 0; i < 4; i++)
            tmp = tmp->next;
        limit = 5;
    } else if (scene->state == 5) {
        for (i = 0; i < 5; i++)
            tmp = tmp->next;
        limit = 8;
    }
    move_mobs(scene, tmp, i, limit);
    display_loop(window, tmp, limit, i);
}