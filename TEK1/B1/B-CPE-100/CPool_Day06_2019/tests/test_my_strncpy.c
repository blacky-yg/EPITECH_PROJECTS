/*
** EPITECH PROJECT, 2019
** test_my_strncpy
** File description:
** test_my_strncpy
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "Hello Word", 5);
    cr_assert_str_eq(dest, "Hello");
}
