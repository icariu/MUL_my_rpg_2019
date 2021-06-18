/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** win
*/

#include "my_rpg.h"

void reset(st_scene *scene)
{
    char **tab = str_to_wordtab(generate_from_file("assets/gen_game"), "\n");
    init_game(scene, tab);
    free_double_array(tab);
    for (int i = 0; scene->inventory->items_activation[i]; i++) {
        if (i == 6)
            scene->inventory->items_activation[i][0] = '1';
        else
            scene->inventory->items_activation[i][0] = '0';
    }
}

void display_win(st_scene *scene, sfRenderWindow *window)
{
    sfText *text;
    sfText *shadow;

    sfRenderWindow_drawSprite(window, scene->menu[0]->spr, NULL);
    if (scene->win == 0) {
        text = init_text("YOU LOSE", (sfVector2f){200, 200}, sfRed, 80);
        shadow = init_text("YOU LOSE", (sfVector2f){202, 202}, sfBlack, 80);
    } else {
        text = init_text("YOU WIN", (sfVector2f){220, 200}, sfGreen, 80);
        shadow = init_text("YOU WIN", (sfVector2f){222, 202}, sfBlack, 80);
    }
    draw_button(scene, "RESTART", (sfVector2f){100, 470}, 0);
    draw_button(scene, "  QUIT", (sfVector2f){450, 470}, 1);
    button_hover(scene, (sfVector2f){100, 470}, 0, 42);
    if (scene->state == 42)
        reset(scene);
    button_hover(scene, (sfVector2f){450, 470}, 1, 0);
    sfRenderWindow_drawText(window, shadow, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfText_destroy(shadow);
}