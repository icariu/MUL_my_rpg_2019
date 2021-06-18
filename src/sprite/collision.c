/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** collision
*/

#include "my_rpg.h"

int char_occurence(char const *str, char chr)
{
    int chr_nb = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == chr)
            chr_nb++;
    }
    return (chr_nb);
}

int target_in_line(sfVector2f target, char *line)
{
    int arr[4];
    char *tmp = malloc(sizeof(char) * my_strlen(line));

    if (tmp == NULL)
        return (2);
    for (int i = 0, tmp_i = 0, arr_i = 0; line[i]; i++, tmp_i++) {
        if (line[i] == ' ') {
            tmp[tmp_i] = '\0';
            arr[arr_i++] = my_getnbr(tmp);
            tmp_i = -1;
        } else
            tmp[tmp_i] = line[i];
    }
    if ((target.x >= arr[0] && target.y >= arr[1] &&
    target.x <= arr[2] && target.y <= arr[3]) || (
    target.x + 30 >= arr[0] && target.y + 50 >= arr[1] &&
    target.x + 30 <= arr[2] && target.y + 50 <= arr[3]))
        return (1);
    free(tmp);
    return (0);
}

int line_valid(char *line)
{
    if (line == NULL)
        return (0);
    for (int i = 0; line[i]; i++) {
        if ((line[i] < '0' || line[i] > '9') &&
        line[i] != ' ' && line[i] != '-' && line[i] != '\n')
            return (0);
        if (line[i] == ' ' &&
        (i == 0 || (line[i - 1] < '0' || line[i - 1] > '9')))
            return (0);
        if (line[i] == '-' && (line[i + 1] < '0' || line[i + 1] > '9'))
            return (0);
        if (line[my_strlen(line) - 2] != ' ' ||
        line[my_strlen(line) - 1] != '\n' || char_occurence(line, ' ') != 4)
            return (0);
    }
    return (1);
}

int target_in_file(sfVector2f target, char *fn)
{
    size_t buff_size = 25;
    FILE *file = fopen(fn, "r");
    char *buff = malloc(sizeof(char) * buff_size);

    if (file == NULL || buff == NULL) {
        my_putstr("Error: can't collision file or memory allocation failed\n");
        return (2);
    }
    while (getline(&buff, &buff_size, file) != -1) {
        if (!line_valid(buff)) {
            my_putstr("Error: unvalid collision file\n");
            return (2);
        } else if (target_in_line(target, buff))
            return (1);
    }
    fclose(file);
    free(buff);
    return (0);
}

int collision_check(st_player *player, int x, int y, int map)
{
    sfVector2f target;
    char *coll_file[6] = {"assets/collisions/1", "assets/collisions/2",
    "assets/collisions/3", "assets/collisions/4", "assets/collisions/5",
    "assets/collisions/6"};

    if (map > 6) {
        my_putstr("Error: can't find a matching collision file\n");
        return (2);
    }
    target.x = player->pos.x + x;
    target.y = player->pos.y + y;
    if (target_in_file(target, coll_file[map - 1]) == 0) {
        player->pos.x = target.x;
        player->pos.y = target.y;
        return (1);
    }
    return (0);
}