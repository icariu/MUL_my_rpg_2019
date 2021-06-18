/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_sprite
*/

#include "my_rpg.h"

void destroy_obj(object **obj, int delete_clock)
{
    for (int i = 0; obj[i]; i++) {
        sfTexture_destroy(obj[i]->texture);
        sfSprite_destroy(obj[i]->spr);
        if (delete_clock)
            sfClock_destroy(obj[i]->clock);
        free(obj[i]);
    }
    free(obj);
}

int destroy(st_scene *scene)
{
    destroy_obj(scene->back, 0);
    destroy_obj(scene->menu, 0);
    destroy_obj(scene->button, 1);
    free_double_array(scene->inventory->items_activation);
    destroy_obj(scene->inventory->items, 0);
    destroy_obj(scene->intro, 1);
    destroy_obj(scene->portal, 1);
    destroy_obj(scene->overlay, 0);
    sfSprite_destroy(scene->player->spr);
    sfSprite_destroy(scene->princess->spr);
    free(scene->player);
    free(scene->princess);
    free(scene->inventory);
    sfRenderWindow_destroy(scene->window);
    sfMusic_destroy(scene->music);
    particles_destroy(scene->rain);
    particles_destroy(scene->snow);
    sfClock_destroy(scene->mobs_clock);
    sfClock_destroy(scene->rain_clock);
    return (0);
}