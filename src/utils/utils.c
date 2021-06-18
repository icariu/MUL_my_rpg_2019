/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** utils
*/

#include "my_rpg.h"

void cursor(st_scene *scene, sfRenderWindow *window)
{
    sfSprite_setPosition(scene->menu[3]->spr, (sfVector2f){
                            sfMouse_getPositionRenderWindow(window).x - 20,
                            sfMouse_getPositionRenderWindow(window).y - 2});
    sfRenderWindow_drawSprite(window, scene->menu[3]->spr, NULL);
}

sfText *init_text(char *name, sfVector2f pos, sfColor col, unsigned int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile
    ("assets/font/PlayfairDisplay-VariableFont_wght.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, name);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, col);
    sfText_setStyle(text, sfTextBold);
    return (text);
}

void draw_button(st_scene *scene, char *text, sfVector2f pos, int button)
{
    sfIntRect rect = scene->button[button]->rect;
    sfSprite *sprite = scene->button[button]->spr;
    sfRenderWindow *window = scene->window;
    sfText *txt;

    txt = init_text(text, (sfVector2f){pos.x + 70, pos.y + 20}, sfBlack, 30);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
}

object **generate_obj(st_scene *scene, int pos, object **object, char **tab)
{
    int len = my_getnbr(tab[pos+1]);
    int k = pos+2;

    object = malloc(sizeof(object) * (len + 1));
    for (int i = 0; k < len + pos + 2; i++, k++)
        object[i] = new_sprite(tab[k]);
    object[len] = NULL;
    return (object);
}