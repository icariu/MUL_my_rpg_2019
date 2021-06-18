/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my_rpg.h"

void button_hover(st_scene *scene, sfVector2f pos, int button, int state_change)
{
    sfTime time = sfClock_getElapsedTime(scene->button[button]->clock);
    float cooldown = (float) time.microseconds / 1000000.0;
    sfRenderWindow *window = scene->window;

    scene->button[button]->rect.left = 0;
    if (sfMouse_getPositionRenderWindow(window).x > pos.x &&
        sfMouse_getPositionRenderWindow(window).x < pos.x + 264 &&
        sfMouse_getPositionRenderWindow(window).y > pos.y &&
        sfMouse_getPositionRenderWindow(window).y < pos.y + 90 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        scene->button[button]->rect.left = 0;
        if (cooldown > 1)
            scene->state = state_change;
    } else if (sfMouse_getPositionRenderWindow(window).x > pos.x &&
        sfMouse_getPositionRenderWindow(window).x < pos.x + 264 &&
        sfMouse_getPositionRenderWindow(window).y > pos.y &&
        sfMouse_getPositionRenderWindow(window).y < pos.y + 90) {
        scene->button[button]->rect.left = 322;
    }
}

void main_menu(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    sfVector2f play_pos = scene->button[0]->pos;
    sfVector2f quit_pos = scene->button[1]->pos;
    sfVector2f settings_pos = scene->button[2]->pos;

    sfRenderWindow_drawSprite(window, scene->menu[0]->spr, NULL);
    display_sprite(scene->button[7]->spr, window, scene->button[7]->pos,
    scene->button[7]->rect);
    htp_button_hover(scene, scene->button[7]->pos, 11);
    draw_button(scene, "  PLAY", play_pos, 0);
    draw_button(scene, "  QUIT", quit_pos, 1);
    draw_button(scene, "SETTINGS", settings_pos, 2);
    button_hover(scene, play_pos, 0, scene->old_state);
    button_hover(scene, quit_pos, 1, 0);
    button_hover(scene, settings_pos, 2, 10);
}