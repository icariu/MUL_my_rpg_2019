/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite
*/

#include "my_rpg.h"

object *new_sprite(char *text)
{
    object *new = malloc(sizeof(object));

    if (new == NULL)
        return (NULL);
    new->texture = sfTexture_createFromFile(text, NULL);
    if (new->texture == NULL)
        return (NULL);
    new->spr = sfSprite_create();
    if (new->spr == NULL)
        return (NULL);
    sfSprite_setTexture(new->spr, new->texture, sfTrue);
    return (new);
}

sfSprite *player_sprite(char *text)
{
    sfVector2f pos = {360, 270};
    sfIntRect rect = {0, 0, 46, 48};
    sfSprite *spr = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(text, NULL);

    sfSprite_setTexture(spr, texture, sfTrue);
    sfSprite_setPosition(spr, pos);
    sfSprite_setTextureRect(spr, rect);
    return (spr);
}

sfSprite *princess_sprite(char *text)
{
    sfVector2f pos = {80, 55};
    sfIntRect rect = {335, 192, 46, 48};
    sfSprite *spr = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(text, NULL);

    sfSprite_setTexture(spr, texture, sfTrue);
    sfSprite_setPosition(spr, pos);
    sfSprite_setTextureRect(spr, rect);
    return (spr);
}

void display_sprite(sfSprite *spr, sfRenderWindow *w, sfVector2f p, sfIntRect r)
{
    sfSprite_setPosition(spr, p);
    sfSprite_setTextureRect(spr, r);
    sfRenderWindow_drawSprite(w, spr, NULL);
}
