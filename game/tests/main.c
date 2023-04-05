/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** main
*/

#include <criterion/criterion.h>
#include <stdio.h>

#include "../includes/jp.h"

Test(json_parser, Read_Simple_Object) {
    parsed_data_t *data = jp_parse("tests.json");
    char *name = jp_search(data, "name")->value.p_str;
    cr_assert_str_eq(name, "Louis");
    free(data);
}

Test(json_parser, Read_Simple_Int) {
    parsed_data_t *data = jp_parse("tests.json");
    int id = jp_search(data, "id")->value.p_int;
    cr_assert(id == 65432123);
    free(data);
}

Test(json_parser, Read_Simple_Bool) {
    parsed_data_t *data = jp_parse("tests.json");
    bool_t my_bool = jp_search(data, "alive")->value.p_bool;
    cr_assert(my_bool == b_true);
    free(data);
}

Test(json_parser, Read_Two_Levels_Object) {
    parsed_data_t *data = jp_parse("tests.json");
    int pos_x = jp_search(data, "pos.x")->value.p_int;
    int pos_y = jp_search(data, "pos.y")->value.p_int;
    cr_assert(pos_x == 5632);
    cr_assert(pos_y == 65131);
    free(data);
}

Test(json_parser, Read_Arr_Of_Int_In_Object) {
    parsed_data_t *data = jp_parse("tests.json");
    int item1 = jp_search(data, "inventory.items[0]")->value.p_int;
    int item2 = jp_search(data, "inventory.items[1]")->value.p_int;
    int item3 = jp_search(data, "inventory.items[2]")->value.p_int;
    cr_assert(item1 == 1);
    cr_assert(item2 == 8);
    cr_assert(item3 == 9);
    free(data);
}

Test(json_parser, Read_Arr_Of_Object_In_Object) {
    parsed_data_t *data = jp_parse("tests.json");
    int item1_id = jp_search(data, "inventory.bag[0].id")->value.p_int;
    char *item1_name = jp_search(data, "inventory.bag[0].name")->value.p_str;
    cr_assert(item1_id == 1);
    cr_assert_str_eq(item1_name, "Popo");
    int item2_id = jp_search(data, "inventory.bag[1].id")->value.p_int;
    char *item2_name = jp_search(data, "inventory.bag[1].name")->value.p_str;
    cr_assert(item2_id == 4);
    cr_assert_str_eq(item2_name, "Shield");
    free(data);
}

Test(json_parser, Write_Simple_Object) {
    parsed_data_t *data = jp_parse("tests.json");

    char *name = jp_search(data, "name")->value.p_str;
    cr_assert_str_eq(name, "Louis");

    jp_search(data, "name")->value.p_str = "Michel";
    jp_write("tests.json", data);

    name = jp_search(data, "name")->value.p_str;
    cr_assert_str_eq(name, "Michel");

    jp_search(data, "name")->value.p_str = "Louis";
    jp_write("tests.json", data);
    free(data);
}

Test(json_parser, Write_Simple_Int) {
    parsed_data_t *data = jp_parse("tests.json");
    int id = jp_search(data, "id")->value.p_int;
    cr_assert(id == 65432123);

    jp_search(data, "id")->value.p_int = 12345678;
    jp_write("tests.json", data);

    id = jp_search(data, "id")->value.p_int;
    cr_assert(id == 12345678);

    jp_search(data, "id")->value.p_int = 65432123;
    jp_write("tests.json", data);
    free(data);
}

Test(json_parser, Read_Float) {
    parsed_data_t *data = jp_parse("tests.json");
    float my_float = jp_search(data, "float")->value.p_float;
    cr_assert(my_float == (float)24.68);

    my_float = jp_search(data, "float2")->value.p_float;
    cr_assert(my_float == (float)42.0);

    free(data);
}
