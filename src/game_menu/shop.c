/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shop
*/

#include "my_rpg.h"

void print_info_object(st_scene *scene, int i)
{
    char *text[8] = {"", "\n+3 strength\n",
                    "\n+5 attack force\n+2 attack speed\n",
                    "\n+10 attack force\n+5 attack speed\n",
                    "\n+10 attack force\n+10 attack speed\n",
                    "\n+1 heart of life\n+3 strength\n",
                    "", ""};
    sfColor color[] = {sfBlack, sfBlack, sfGreen, sfRed, sfRed,
                        sfBlue, sfBlack, sfBlack};
    sfText *txt;
    sfText *title;
    char *str_title[] = {"", "Wooden Ring", "Silver Ring", "Golden Ring",
                        "Sword", "Shield", "", "", ""};
    txt = init_text(text[i], (sfVector2f){447, 200}, sfBlack, 30);
    title = init_text(str_title[i], (sfVector2f){447, 145}, color[i], 40);
    sfRenderWindow_drawText(scene->window, title, NULL);
    sfRenderWindow_drawText(scene->window, txt, NULL);
    sfText_destroy(title);
    sfText_destroy(txt);
}

void hover_shop(st_scene *scene, sfVector2f p, sfVector2f size, int i)
{
    static int purchase[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int price[] = {10, 100, 200, 300, 500, 400, 600, 700, 0};
    char *str_price = my_strdup("xp needed : ");
    str_price = my_strcat(str_price, my_itoa(price[i]));
    sfText *text = init_text(str_price, (sfVector2f){447, 387}, sfBlack, 30);
    sfRenderWindow *window = scene->window;

    scene->inventory->items[i]->rect.left = 0;
    if (M_POS_X > p.x && M_POS_X < p.x + size.x && M_POS_Y > p.y && M_POS_Y <
    p.y + size.y && sfMouse_isButtonPressed(0) == 1 && scene->xp >= price[i]) {
        purchase[i] = 1;
        scene->xp -= price[i];
        scene->inventory->items_activation[i][0] = '1';
    } else if (M_POS_X > p.x && M_POS_X < p.x + size.x && M_POS_Y > p.y &&
        M_POS_Y < p.y + size.y) {
        if (purchase[i] == 1) sfText_setColor(text, sfRed);
        sfRenderWindow_drawText(window, text, NULL);
        print_info_object(scene, i);
    }
    free(str_price);
    sfText_destroy(text);
}

void display_shop(st_scene *scene, sfRenderWindow *window, sfEvent event, int i)
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfText *text = init_text("SHOP", (sfVector2f){320, 45}, sfBlack, 60);

    sfRenderWindow_drawSprite(window, scene->back[i]->spr, NULL);
    sfRenderWindow_drawSprite(window, scene->menu[2]->spr, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    for (int i = 1; scene->inventory->items[i+2]; i++) {
        sprite = scene->inventory->items[i]->spr;
        rect = scene->inventory->items[i]->rect;
        pos = scene->inventory->items[i]->pos;
        rect.left += 100;
        display_sprite(sprite, window, pos, rect);
        hover_shop(scene, pos, (sfVector2f){100, 100}, i);
    }
    display_sprite(scene->inventory->items[7]->spr, window,
    scene->inventory->items[7]->pos, scene->inventory->items[7]->rect);
    button_back_hover(scene, scene->inventory->items[7]->pos, scene->old_state);
    sfText_destroy(text);
}