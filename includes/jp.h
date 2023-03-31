/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** json_parser
*/


#ifndef _JSON_PARSER_H__
    #define _JSON_PARSER_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <aio.h>
    #include <unistd.h>
    #include <fcntl.h>

    typedef struct parsed_data_s parsed_data_t;

    // Structures
    #ifndef _JSON_PARSER_STRUCT_H__
        #define _JSON_PARSER_STRUCT_H__

        typedef enum bool_s {
            b_false,
            b_true
        } bool_t;

        typedef enum type_s {
            p_int,
            p_bool,
            p_str,
            p_obj,
            p_arr,
            p_float,
            p_null
        } type_t;

        typedef union values_s {
            int p_int;
            double p_float;
            char *p_str;
            bool_t p_bool;
            parsed_data_t *p_arr;
            parsed_data_t *p_obj;
        } values_t;

        typedef struct parsed_data_s {
            char *name;
            type_t type;
            values_t value;
            struct parsed_data_s *next;
        } parsed_data_t;

    #endif

    void load_file_in_str(char const *filepath, char **str);
    int my_getnbr(char *str);
    int my_nbrlen(long int nb);
    double my_getnbr_float(char *str);
    int my_strlen(char const *str);
    int my_is_a_float(char *str);
    long int my_compute_power_rec(long int nb, int p);
    int my_strcmp(char const *s1, char const *s2);


    void jp_skipspaces(char **str);
    void jp_getvalue_int(char **str, parsed_data_t *data);
    void jp_getvalue(char **str, parsed_data_t *data);
    void jp_getvalue_bool(char **str, parsed_data_t *data);
    char *jp_getvalue_string(char **str);

    parsed_data_t *load_array(char **str);
    parsed_data_t *load_object(char **str);
    parsed_data_t *jp_parse(char *filepath);
    parsed_data_t *jp_search(parsed_data_t *data, char *name);
    void jp_write(char *filepath, parsed_data_t *object);

    char *get_name_without_arr(char *str);
    int is_array(char *name);
    char *get_name(char *name);
    int name_len(char *name);


    void jp_writedata(int fd, parsed_data_t *data, int tab_count);
    void jp_writestr(int fd, char *str);
    void jp_writeint(int fd, int nb);
    void jp_writebool(int fd, bool_t value);
    void jp_writetab(int fd, int tab_count);
    void jp_writearray(int fd, parsed_data_t *data, int tab_count);
    void jp_writedata_name(int fd, parsed_data_t *data, int tab_count);
    void jp_writedata_value(int fd, parsed_data_t *data, int tab_count);

#endif
