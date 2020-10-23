/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int dest_len = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
