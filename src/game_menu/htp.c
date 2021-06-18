/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** htp
*/

#include "my_rpg.h"

void htp_button_hover(st_scene *scene, sfVector2f pos, int state_change)
{
    sfTime time = sfClock_getElapsedTime(scene->button[7]->clock);
    float cooldown = (float) time.microseconds / 1000000.0;
    sfRenderWindow *window = scene->window;

    scene->button[7]->rect.left = 0;
    if (sfMouse_getPositionRenderWindow(window).x > pos.x &&
        sfMouse_getPositionRenderWindow(window).x < pos.x + 100 &&
        sfMouse_getPositionRenderWindow(window).y > pos.y &&
        sfMouse_getPositionRenderWindow(window).y < pos.y + 100 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        scene->button[7]->rect.left = 0;
        if (cooldown > 1)
            scene->state = state_change;
    } else if (sfMouse_getPositionRenderWindow(window).x > pos.x &&
        sfMouse_getPositionRenderWindow(window).x < pos.x + 100 &&
        sfMouse_getPositionRenderWindow(window).y > pos.y &&
        sfMouse_getPositionRenderWindow(window).y < pos.y + 100) {
        scene->button[7]->rect.left += 100;
    }
}

void display_htp(st_scene *scene, sfRenderWindow *window)
{
    char *zqsd = "USE THOSE KEY TO MOVE\n   FORWARD('Z')\n"
    "   BACKWARD('S')\n   LEFT('Q')\n   RIGHT('D')\n";
    char *e = "USE THIS KEY TO OPEN\nTHE INVENTORY";
    char *r = "USE THIS KEY TO OPEN\nTHE SHOP IN THE TAUNT";
    char *esc = "USE THIS KEY TO RETURN\nTO THE MENU";
    char *arg[] = {zqsd, e, r, esc, NULL};
    sfVector2f pos[] = {{460, 30}, {460, 270}, {460, 370}, {460, 470}};

    sfText *text;
    sfRenderWindow_drawSprite(window, scene->menu[4]->spr, NULL);
    for (int i = 0; arg[i]; i++) {
        text = init_text(arg[i], pos[i], sfBlack, 20);
        sfRenderWindow_drawText(window, text, NULL);
    }
    display_sprite(scene->inventory->items[7]->spr, window,
    scene->inventory->items[7]->pos, scene->inventory->items[7]->rect);
    button_back_hover(scene, scene->inventory->items[7]->pos, 7);
    sfText_destroy(text);
}