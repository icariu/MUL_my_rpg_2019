/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create
*/

#include "my_rpg.h"

void display_dialog(st_scene *scene, sfVector2f txt, sfVector2f ble, char *text)
{
    sfText *diag = init_text(text, txt, sfBlack, 12);
    sfSprite_setPosition(scene->back[6]->spr, ble);
    sfRenderWindow_drawSprite(scene->window, scene->back[6]->spr, NULL);
    sfRenderWindow_drawText(scene->window, diag, NULL);
    sfText_destroy(diag);
}

void first_dialog(sfRenderWindow *window, st_scene *scene)
{
    char *text[] = {"", "    Defeat the \nenemies and free\n  our princess!",
    "    You need to \ntravel to find her, \n  by looting ...",
    "   ...enemies to\n upgrade your\n   equipment.",
    "    Go in the tent\nto talk with craf-\n  tman...",
    "   ...to upgrade\nyour weapons."};

    if (scene->nb_dial_f > 5)
        return;
    display_dialog(scene, (sfVector2f){295, 150},
    (sfVector2f){290, 140}, text[scene->nb_dial_f]);
}

void craftman_dialog(sfRenderWindow *window, st_scene *scene)
{
    char *text[] = {"    Hello there!", "    Welcome in\n    my store,\n",
    "    I'm Tod!",
    "    Here you can:\n",
    "    upgrade your\n    equipment,",
    "       and buy\n different items\n (click on the one\n",
    "    you are\n    interested in\n    to buy it).",
    "    To open the\n  shop, press 'R'."};

    if (scene->nb_dial_c > 7)
        return;
    display_dialog(scene, (sfVector2f){540, 295},
    (sfVector2f){535, 285}, text[scene->nb_dial_c]);
}

void princess_dialog(sfRenderWindow *window, st_scene *scene, sfEvent event)
{
    return;
}