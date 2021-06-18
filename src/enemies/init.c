/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init
*/

#include "my_rpg.h"

sfSprite *enemy_sprite_1(char *text, int type)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 46, 48};
    sfSprite *spr = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(text, NULL);

    if (type == 2) {
        rect.left = 0;
        rect.top = 192;
    }
    sfSprite_setTexture(spr, texture, sfTrue);
    sfSprite_setPosition(spr, pos);
    sfSprite_setTextureRect(spr, rect);
    return (spr);
}

void init_foes(st_scene *scene, int pos, char **tab)
{
    st_foes *foes = NULL;
    int type = my_getnbr(tab[pos+1]);

    foes = malloc(sizeof(st_foes));
    foes->spr = enemy_sprite_1(tab[pos+2], type);
    foes->life = my_getnbr(tab[pos+3] + 5);
    foes->pos.x = my_getnbr(tab[pos+4] + 6);
    foes->pos.y = my_getnbr(tab[pos+5] + 6);
    foes->rect.left = my_getnbr(tab[pos+6] + 10);
    foes->rect.top = my_getnbr(tab[pos+7] + 9);
    foes->rect.width = my_getnbr(tab[pos+8] + 11);
    foes->rect.height = my_getnbr(tab[pos+9] + 12);
    foes->next = NULL;
    if (!scene->control->head) {
        scene->control->head = foes;
        scene->control->tail = foes;
    } else {
        scene->control->head->next = foes;
        scene->control->head = foes;
    }
}