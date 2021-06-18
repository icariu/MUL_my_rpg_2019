/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** verif_params
*/

#include "my_rpg.h"

int verif_params(char *path, int equal, char *arg[])
{
    DIR *directory = opendir(path);
    struct dirent *read_it;
    int count = 0;

    if (!directory)
        return (84);

    while ((read_it = readdir(directory))) {
        for (int i = 0; arg[i]; i++) {
            if (my_strncmp(arg[i], read_it->d_name, my_strlen(arg[i])) == 0) {
                count++;
            }
        }
    }
    if (count != equal)
        return (84);
    return (0);
}

int write_error(void)
{
    write(2, "MISS RESSOURCES\n", 17);
    return (84);
}

int check_folder_exist(void)
{
    char *arg[] = {"font", "inventory_gen", "collisions", ".", "..",
    "default_button_gen", "gen_game", "music", "img", NULL};
    char *img[] = {"1.png", "arrow.png", "back_button.png", "castle_intro.png",
    "cursor.png", "default_button.png", "game_menu.png", "htp_button.png",
    "htp.png", "inventory.png", "knight.jpg", "map1.jpg", "map2.jpg",
    "map3.png", "map4.png", "map5.png", "map6.png", "shop.png", "overlay.png",
    "slider_button.png", "slider.png", "items", ".", "..", "portal.png", NULL};
    char *music[] = {"game.ogg", ".", "..", NULL};
    char *items[] = {"gold_ring.png", "key.png", "quest_book.png", "shield.png",
    "silver_ring.png", "sword.png", "wood_ring.png", ".", "..", NULL};
    char *font[] = {".", "..", "PlayfairDisplay-VariableFont_wght.ttf", NULL};
    char *collisions[] = {"1", "2", "3", "4", "5", "6", ".", "..", NULL};

    if (verif_params("assets", 10, arg) || verif_params("assets/img/", 26, img)
    || verif_params("assets/music/", 4, music) ||
    verif_params("assets/img/items/", 10, items) ||
    verif_params("assets/font/", 4, font) ||
    verif_params("assets/collisions/", 9, collisions))
        return (write_error());
    return (0);
}