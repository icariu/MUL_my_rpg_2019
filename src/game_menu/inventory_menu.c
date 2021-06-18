/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_menu
*/

#include "my_rpg.h"

void button_back_hover(st_scene *scene, sfVector2f pos, int state_change)
{
    sfTime time = sfClock_getElapsedTime(scene->inventory->items[7]->clock);
    float cooldown = (float) time.microseconds / 1000000.0;
    sfRenderWindow *window = scene->window;

    scene->inventory->items[7]->rect.left = 0;
    if (sfMouse_getPositionRenderWindow(window).x > pos.x &&
        sfMouse_getPositionRenderWindow(window).x < pos.x + 100 &&
        sfMouse_getPositionRenderWindow(window).y > pos.y &&
        sfMouse_getPositionRenderWindow(window).y < pos.y + 100 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        scene->inventory->items[7]->rect.left = 0;
        if (cooldown > 1)
            scene->state = state_change;
    } else if (sfMouse_getPositionRenderWindow(window).x > pos.x &&
        sfMouse_getPositionRenderWindow(window).x < pos.x + 100 &&
        sfMouse_getPositionRenderWindow(window).y > pos.y &&
        sfMouse_getPositionRenderWindow(window).y < pos.y + 100) {
        scene->inventory->items[7]->rect.left += 100;
    }
}

void inventory_menu(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    int i = scene->background_index;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfText *text = init_text("Inventory", (sfVector2f){308, 32}, sfWhite, 42);
    sfRenderWindow_drawSprite(window, scene->back[i]->spr, NULL);
    sfRenderWindow_drawSprite(window, scene->menu[1]->spr, NULL);
    sfRenderWindow_drawText(window, text, NULL);

    for (int i = 0; scene->inventory->items[i]; i++) {
        sprite = scene->inventory->items[i]->spr;
        rect = scene->inventory->items[i]->rect;
        pos = scene->inventory->items[i]->pos;
        if (scene->inventory->items_activation[i][0] == '1')
            rect.left += 100;
        sfSprite_setTextureRect(sprite, rect);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    button_back_hover(scene, scene->inventory->items[7]->pos, scene->old_state);
}