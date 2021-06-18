/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** settings_menu
*/

#include "my_rpg.h"

void sound_slider(st_scene *scene, float volume_pos[], float min_x)
{
    sfRenderWindow *window = scene->window;
    int volume[] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; volume_pos[i]; i++) {
        if (M_POS_X > (volume_pos[i] + min_x))
            sfMusic_setVolume(scene->music, volume[i]);
        else if (M_POS_X < (volume_pos[0] + min_x))
            sfMusic_setVolume(scene->music, 0.00);
    }
}

void slider_hover(st_scene *scene, sfRenderWindow *window, int i)
{
    float max_x = scene->button[i]->pos.x + scene->button[i]->rect.width;
    float min_x = scene->button[i]->pos.x;
    int height = scene->button[i+1]->rect.height;
    int width = scene->button[i+1]->rect.width;
    sfVector2f pos_button = scene->button[i+1]->pos;
    float eq = max_x - min_x;
    float volume_pos[] = {eq/5, (eq/5)*2, (eq/5)*3, (eq/5)*4, eq, 0};

    if (M_POS_X > min_x + 10 && M_POS_X < max_x - 10 && M_POS_Y > pos_button.y
    && M_POS_Y < pos_button.y + height && sfMouse_isButtonPressed(0) == 1 &&
    M_POS_X > pos_button.x && M_POS_X < pos_button.x + width) {
        scene->button[i+1]->pos = (sfVector2f){M_POS_X - 24, pos_button.y};
        sound_slider(scene, volume_pos, min_x);
    }
}

void settings_difficulty(st_scene *scene, sfRenderWindow *window, int i)
{
    static char *difficulty[] = {"   EASY", "NORMAL", "   HARD"};
    sfVector2f pos_left = scene->button[6]->pos;
    sfVector2f pos_right = scene->button[3]->pos;
    sfIntRect rect = scene->button[6]->rect;
    pos_left.x -= rect.width;

    if (M_POS_X > pos_left.x && M_POS_X < pos_left.x + rect.width &&
    M_POS_Y > pos_left.y && M_POS_Y < pos_left.y + rect.height &&
    sfMouse_isButtonPressed(0) == 1 && scene->difficulty > 0)
        scene->difficulty--;
    else if (M_POS_X > pos_right.x && M_POS_X < pos_right.x + rect.width &&
    M_POS_Y > pos_right.y && M_POS_Y < pos_right.y + rect.height &&
    sfMouse_isButtonPressed(0) == 1 && scene->difficulty < 2)
        scene->difficulty++;
    draw_button(scene, difficulty[i], (sfVector2f){268, 300}, 1);
}

void settings_menu(st_scene *scene, sfRenderWindow *window, sfEvent evt)
{
    sfVector2f pos;

    sfRenderWindow_drawSprite(window, scene->menu[0]->spr, NULL);
    display_sprite(scene->inventory->items[7]->spr, window,
    scene->inventory->items[7]->pos, scene->inventory->items[7]->rect);
    settings_difficulty(scene, window, scene->difficulty);
    for (int i = 3; i < 7; i++) {
        pos = scene->button[i]->pos;
        sfSprite_setPosition(scene->button[i]->spr, pos);
        if (i == 6) {
            pos.y += scene->button[i]->rect.height;
            sfSprite_setPosition(scene->button[i]->spr, pos);
            sfSprite_setRotation(scene->button[i]->spr, 180);
        }
        sfRenderWindow_drawSprite(window, scene->button[i]->spr, NULL);
    }
    slider_hover(scene, window, 4);
    button_back_hover(scene, scene->inventory->items[7]->pos, 7);
    draw_button(scene, "VOLUME", (sfVector2f){268, 100}, 1);
}