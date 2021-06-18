/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particles
*/

#include "my_rpg.h"

void particule_set(sfRectangleShape *particle, char type, int len, int max_w)
{
    sfColor color = sfColor_fromRGBA(255, 255, 255, 255);
    sfVector2f size;

    if (type == 'B') {
        color = sfColor_fromRGBA(0, 0, 255, 200);
        size.y = len;
        size.x = rand() % max_w;
    } else {
        size.y = rand() % max_w;
        size.x = size.y;
    }
    sfRectangleShape_setSize(particle, size);
    sfRectangleShape_setFillColor(particle, color);
}

sfRectangleShape **particles_gen(int nb, int max_w, int len, char type)
{
    sfRectangleShape **dest = malloc(sizeof(sfRectangleShape *) * (nb + 1));
    sfVector2f pos;

    srand(time(NULL));
    if (dest == NULL)
        return (NULL);
    for (int i = 0; i < nb; i++) {
        pos.x = rand() % W_L;
        pos.y = -1 * rand() % 40 * len;
        dest[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(dest[i], pos);
        particule_set(dest[i], type, len, max_w);
    }
    dest[nb] = NULL;
    return (dest);
}

int particles_draw(sfRectangleShape **particles, sfRenderWindow *window,
                    sfClock *clock)
{
    sfVector2f pos;
    sfTime time = sfClock_getElapsedTime(clock);
    float second = (float) time.microseconds / 1000000.0;

    if (particles == NULL)
        return (1);
    for (int i = 0; particles[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window, particles[i], NULL);
        pos = sfRectangleShape_getPosition(particles[i]);
        pos.y += 4 * sfRectangleShape_getSize(particles[i]).x;
        if (pos.y > W_H) {
            pos.x = rand() % W_L;
            pos.y = -1 * sfRectangleShape_getPosition(particles[i]).x;
        }
        if (second > 0.02) {
            sfClock_restart(clock);
            sfRectangleShape_setPosition(particles[i], pos);
        }
    }
    return (0);
}

int particles_destroy(sfRectangleShape **particles)
{
    if (particles == NULL)
        return (1);
    for (int i = 0; particles[i] != NULL; i++)
        sfRectangleShape_destroy(particles[i]);
    return (0);
}