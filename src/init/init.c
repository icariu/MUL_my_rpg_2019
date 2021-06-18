/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_button
*/

#include "my_rpg.h"

void init_inventory(st_scene *scene)
{
    char *gen = generate_from_file("assets/inventory_gen");
    char **tab = str_to_wordtab(gen, "\n");
    int nb_items = my_getnbr(tab[1]);
    int k = 2;

    scene->inventory->items_activation = malloc(sizeof(char *) * (nb_items+1));
    for (int i = 0; i < nb_items; i++, k += 8) {
        scene->inventory->items[i]->pos.x = my_getnbr(tab[k+1] + 6);
        scene->inventory->items[i]->pos.y = my_getnbr(tab[k+2] + 6);
        scene->inventory->items[i]->rect.left = my_getnbr(tab[k+3] + 10);
        scene->inventory->items[i]->rect.top = my_getnbr(tab[k+4] + 9);
        scene->inventory->items[i]->rect.width = my_getnbr(tab[k+5] + 11);
        scene->inventory->items[i]->rect.height = my_getnbr(tab[k+6] + 12);
        scene->inventory->items_activation[i] = my_strdup(tab[k+7] + 9);
    }
    scene->inventory->items_activation[nb_items] = NULL;
    scene->inventory->items[nb_items-1]->clock = sfClock_create();
    free(gen);
    free_double_array(tab);
}

void init_button(st_scene *scene)
{
    char *gen = generate_from_file("assets/default_button_gen");
    char **tab = str_to_wordtab(gen, "\n:");
    int nb_button = my_getnbr(tab[1]);
    char *path = tab[3];
    int k = 8;

    for (int i = 0; i < nb_button; i++, k += 8) {
        scene->button[i]->pos.x = my_getnbr(tab[k]);
        scene->button[i]->pos.y = my_getnbr(tab[k+1]);
        scene->button[i]->rect.top = my_getnbr(tab[k+3]);
        scene->button[i]->rect.left = my_getnbr(tab[k+4]);
        scene->button[i]->rect.width = my_getnbr(tab[k+5]);
        scene->button[i]->rect.height = my_getnbr(tab[k+6]);
        scene->button[i]->clock = sfClock_create();
    }
    free_double_array(tab);
    free(gen);
}

void init_player(st_scene *scene, int pos, char **tab)
{
    scene->player = malloc(sizeof(st_player));
    scene->player->spr = player_sprite(tab[pos+2]);
    scene->player->life = my_getnbr(tab[pos+3] + 5);
    scene->player->pos.x = my_getnbr(tab[pos+4] + 6);
    scene->player->pos.y = my_getnbr(tab[pos+5] + 6);
    scene->player->rect.left = my_getnbr(tab[pos+6] + 10);
    scene->player->rect.top = my_getnbr(tab[pos+7] + 9);
    scene->player->rect.width = my_getnbr(tab[pos+8] + 11);
    scene->player->rect.height = my_getnbr(tab[pos+9] + 12);
}

void init_assets(st_scene *scene)
{
    char **tab = str_to_wordtab(generate_from_file("assets/gen_game"), "\n");
    for (int i = 0; tab[i]; i++) {
        if (!my_strncmp("# background", tab[i], 12))
            scene->back = generate_obj(scene, i, scene->back, tab);
        if (!my_strncmp("# menu", tab[i], 6))
            scene->menu = generate_obj(scene, i, scene->menu, tab);
        if (!my_strncmp("# button", tab[i], 8))
            scene->button = generate_obj(scene, i, scene->button, tab);
        if (!my_strncmp("# player", tab[i], 8))
            init_player(scene, i, tab);
        if (!my_strcmp("# foes", tab[i]))
            init_foes(scene, i, tab);
        if (!my_strncmp("# inventory", tab[i], 11))
            scene->inventory->items = generate_obj(scene, i,
            scene->inventory->items, tab);
        if (!my_strncmp("# intro", tab[i], 7))
            init_intro(scene, i, tab);
        if (!my_strncmp("# portal", tab[i], 8)) init_portal(scene, i, tab);
    }
    free_double_array(tab);
}

int initialise(st_scene *scene)
{
    char **tab = str_to_wordtab(generate_from_file("assets/gen_game"), "\n");
    scene->control = malloc(sizeof(control_t));
    scene->control->head = NULL;
    scene->control->tail = NULL;
    scene->mobs_clock = sfClock_create();
    scene->rain_clock = sfClock_create();
    scene->inventory = malloc(sizeof(st_inventory));
    init_assets(scene);
    init_inventory(scene);
    init_button(scene);
    init_music(scene);
    init_game(scene, tab);
    scene->princess = malloc(sizeof(st_player));
    scene->princess->spr = princess_sprite("assets/img/knight.jpg");
    scene->rain = particles_gen(35, 10, 30, 'B');
    scene->snow = particles_gen(35, 10, 30, 'W');
    scene->overlay = malloc(sizeof(object) * 2);
    scene->overlay[0] = new_sprite("assets/img/overlay.png");
    scene->overlay[1] = NULL;
    return (free_double_array(tab));
}