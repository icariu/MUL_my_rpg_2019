/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "my_rpg.h"

void user_input(st_scene *scene, sfEvent event)
{
    if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyE &&
        scene->state < 7)) {
        scene->old_state = scene->state;
        scene->state = 8;
    } if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyR
    && scene->state == 6)) {
        scene->old_state = scene->state;
        scene->state = 9;
    } if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
        if (scene->state < 7) {
            scene->old_state = scene->state;
            scene->state = 12;
            return;
        } if (scene->state != 8 && scene->state == 7)
            sfRenderWindow_close(scene->window);
        else if (scene->state != 8)
            scene->state = 7;
    }
    if (event.type == sfEvtClosed || scene->state == 0)
        sfRenderWindow_close(scene->window);
}

void which_window(st_scene *scene, sfRenderWindow *window)
{
    int const important_status[] = {1, 2, 3, 4, 5, 6, 11, 12, 13, 0};
    replace_w const diff_func[] = {&if_one_w, &if_two_w, &if_three_w,
    &if_four_w, &if_five_w, &if_six_w, &if_eleven, &if_twelve,
    &if_thirteen, NULL};
    int i = 0;

    while (important_status[i]) {
        if (important_status[i] == scene->state) {
            (diff_func[i])(scene, window);
            break;
        }
        i++;
    }
}

void which_window_event(st_scene *scene, sfRenderWindow *window, sfEvent event)
{
    int const important_status[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    replace const diff_func[] = {&if_one, &if_two, &if_three, &if_four,
    &if_five, &if_six, &if_seven, &if_eight, &if_nine, &if_ten, NULL};
    int i = 0;

    while (important_status[i]) {
        if (important_status[i] == scene->state) {
            (diff_func[i])(scene, window, event);
            break;
        }
        i++;
    }
}

void main_loop(sfRenderWindow *window, st_scene *scene)
{
    sfEvent event;

    display_intro(scene, window);
    sound_gestion(scene);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            user_input(scene, event);
            which_window_event(scene, window, event);
        }
        which_window(scene, window);
        cursor(scene, window);
        overlay(scene, window);
        sfRenderWindow_display(window);
    }
}

int main(int ac, char **av)
{
    st_scene scene;
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    if (ac > 3)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_usage();
        return (0);
    } else if (ac != 1)
        return (84);
    if (check_folder_exist() == 84)
        return (84);
    if (initialise(&scene) == 84)
        return (84);
    window = sfRenderWindow_create(mode, "H E R", sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    scene.window = window;
    main_loop(window, &scene);
    return (destroy(&scene));
}