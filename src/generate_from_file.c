/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_from_file
*/

#include "my_rpg.h"

char *generate_from_file(char *to_read)
{
    char *read = "";
    char *oldread = malloc(sizeof(char) * 1);
    size_t len = 0;
    ssize_t readed = -1;
    FILE *file = fopen(to_read, "r");

    oldread[0] = '\0';
    if (file == NULL) {
        write(2, "Error in reading file :", 23);
        write(2, to_read, my_strlen(to_read));
        write(2, "\n", 1);
        return (NULL);
    }
    while ((readed = getline(&read, &len, file)) != -1)
        oldread = my_strcat(oldread, read);
    fclose(file);
    free(read);
    return (oldread);
}