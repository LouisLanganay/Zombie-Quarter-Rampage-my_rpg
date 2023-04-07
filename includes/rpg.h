/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/


#ifndef _RPG_H__
    #define _RPG_H__

    #include "gl.h"
    #include "jp.h"
    #include "view.h"
    #include "player.h"

    #define WINDOW_NAME "RPG"

    #define MINECRAFT_FONT 8888
    #define CRYSTAL_FONT 8889
    #define TLOU_FONT 8890

    #define SPLASH_SCREEN_TEXT1 9999
    #define SPLASH_SCREEN_TEXT2 10001

    #define EVENT_WINDOW_CLOSE 1
    #define EVENT_INVENTORY_OPEN 454545
    #define INVENTORY_SIZE 16

    #define EVENT_DIALOGUE_CHOICE 651546

    #define RPA rpg->player->assets
    #define RGW rpg->glib->window
    #define RPK rpg->player->keys
    #define RPH rpg->player->hitbox
    #define RSG rpg->settings->game_language
    #define PA player->assets
    #define RSNI rpg->save->npc_interactions
    #define RPAQ rpg->player->assets->quest_icons


    #define GET_SAVE_GAMELANGUAGE my_strcmp(jp_search(data, \
        "game_language")->value.p_str, "fr") == 0 ? FR : EN;

    typedef struct pos_s {
        int x;
        int y;
    } pos_t;

    typedef struct tiled_object_s {
        char *name;
        int id;
        float height;
        float width;
        sfVector2f pos;
        struct tiled_object_s *next;
    } tiled_object_t;

    typedef struct tile_s {
        int id;
        struct tiled_object_s *colisions;
        struct tile_s *next;
    } tile_t;

    typedef struct layer_s {
        int id;
        char *class;
        char *name;
        int opacity;
        char *type;
        bool_t visible;
        int width;
        int height;
        int tiles_count;
        pos_t *pos;
        int z_index;
        int *data;
        char *color;
        struct tiled_object_s *objects;
        sfSprite **sprites;
        struct layer_s *next;
    } layer_t;

    typedef struct tilesets_l {
        char *name;
        char *path;
        int tile_count;
        int width;
        int height;
        struct tilesets_l *next;
    } tilesets_t;

    typedef struct dialog_option_s {
        char *text;
        char *next_dialog;
    } dialog_option_t;

    typedef struct dialog_func_s {
        char *name;
        void (*func)(void*);
    } dialog_func_t;

    typedef struct dialog_s {
        char *name;
        char *text;
        char *function;
        dialog_option_t **options;
        struct dialog_s *next;
    } dialog_t;

    typedef struct npc_s {
        char *name;
        char *texture_path;
        char *default_dialog;
        bool_t one_time;
        sfVector2f pos;
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        dialog_t *dialogs;
        struct npc_s *next;
    } npc_t;

    typedef struct map_s {
        char *map_path;
        char *map_name;
        int map_width;
        int map_height;
        int tile_width;
        int tile_height;
        char *tileset_path;
        sfTexture **textures;
        layer_t *layers;
        npc_t *npcs;
        struct tilesets_l *tilesets;
        struct tile_s *tiles;
        struct map_s *next;
    } map_t;

    typedef enum language_type_e {
        FR,
        EN
    } language_type_t;

    typedef struct languages_s {
        char *name;
        char *fr;
        char *en;
    } languages_t;

    typedef struct settings_s {
        language_type_t game_language;
    } settings_t;

    typedef struct save_s {
        int loaded;
        char *name;
        char *path;
        char *format;
        char **npc_interactions;
    } save_t;

    typedef struct splash_screen_s {
        sfClock *clock;
    } splash_screen_t;

    typedef struct quests_func_s {
        char *name;
        void (*func)(void*);
    } quests_func_t;

    typedef struct quest_s {
        char *id;
        char *name;
        char *description;
        char *type;
        char *func;
        struct quest_s *next;
    } quest_t;

    typedef struct rpg_s {
        int debug;
        char *actual_map;
        int game_started;
        int maps_loaded;
        dialog_t *actual_dialog;
        npc_t *actual_npc;
        map_t *maps;
        GLib_t *glib;
        player_t *player;
        languages_t **languages;
        settings_t *settings;
        save_t *save;
        splash_screen_t *splash_screen;
        quest_t *quests;
        char **quests_in_progress;
    } rpg_t;

    typedef struct keyboard_images_s {
        sfKeyCode key;
        int id;
    } keyboard_images_t;

    typedef struct interactions_s {
        char *name;
        void (*func)(rpg_t *, sfVector2f pos);
    } interactions_t;

    int my_strcmp(char const *s1, char const *s2);
    char *my_strcat(char *dest, char const *src);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcat_malloc(char *dest, char const *src);
    char *my_strdup(char *str);
    int my_strlen(char const *str);
    char *my_strndup(const char *str, int n);
    int get_mid_char(const char *str);
    int my_arr_contains(char **arr, char *str);
    int my_arrlen(char **arr);

    /* GAME */
    void game_loop(rpg_t *rpg);
    void start_game(rpg_t *rpg);

    /* SPLASH SCREEN */
    void draw_splash_screen(rpg_t *rpg);
    void init_splash_screen(rpg_t *rpg);

    /* LANGUAGE */
    char *get_language(rpg_t *rpg, char *name, language_type_t language);

    /* SAVE */
    int load_game(rpg_t *rpg, parsed_data_t *data);
    int load_save(rpg_t *rpg, char *path);
    int load_npc_interactions(save_t *save, parsed_data_t *data);
    int load_player(player_t *player, parsed_data_t *data);
    int load_quests_in_progress(rpg_t *rpg, parsed_data_t *data);
    void save_npc_interactions(rpg_t *rpg, npc_t *npc);
    void save_game(rpg_t *rpg);
    void save_quests_in_progress(rpg_t *rpg);
    void save_player(rpg_t *rpg);

    /* QUESTS */
    void start_quest(rpg_t *rpg, char *id);
    quest_t *get_quest(rpg_t *rpg, char *id);
    void draw_quests(rpg_t *rpg);
    quests_func_t *get_quests_func_arr(void);
    quest_t *get_quest_by_id(rpg_t *rpg, char *id);
    void stop_quest(rpg_t *rpg, char *id);

    /* MAP */
    void load_maps(rpg_t *rpg);
    int create_map(rpg_t *rpg, char *json_path);
    sfTexture **load_tiles_textures(map_t *map);
    sfSprite **load_layer_sprites(layer_t *layer, map_t *map);
    int load_map_layers(map_t *map, parsed_data_t *data);
    void load_layer_objects(parsed_data_t *data, layer_t *layer);
    void load_tiles_colisions(map_t *map, parsed_data_t *data);
    void load_tilesets(parsed_data_t *data, map_t *map);
    int *load_layer_data_arr(parsed_data_t *data);
    void draw_map(map_t *map, char *json_path, rpg_t *rpg);
    void draw_layer(rpg_t *rpg, layer_t *layer);
    void draw_layer_by_class(map_t *map, rpg_t *rpg, char *class);
    void draw_layer_by_order(map_t *map, rpg_t *rpg, int order);
    void draw_inventory(rpg_t *rpg);
    void draw_items(rpg_t *rpg);
    map_t *get_map(rpg_t *rpg, char *map_path);

    /* VIEW */
    void set_view_on_player(rpg_t *rpg);

    /* PLAYER */
    int get_key_id(sfKeyCode key, rpg_t *rpg);
    void *key_pressed(rpg_t *rpg);
    void draw_player(rpg_t *rpg);
    void change_player_rect(player_t *player);
    void check_player_moovment(player_t *player, map_t *map, rpg_t *rpg);
    int check_colisions(
        map_t *map,
        sfVector2f pos,
        player_t *player,
        rpg_t *rpg
    );
    void check_interactions(player_t *player, map_t *map, rpg_t *rpg);
    keyboard_images_t *get_keyboard_array(void);

    /* NPC */
    npc_t *get_npc(map_t *map, char *name);
    void draw_npcs(map_t *map, rpg_t *rpg);
    void start_dialogue(rpg_t *rpg, npc_t *npc);
    void next_dialogue(rpg_t *rpg, int choice);
    void display_dialogue(rpg_t *rpg);
    dialog_func_t *get_npc_func_arr(void);
    void check_dialogue_function(rpg_t *rpg, dialog_t *dialogue);

    /* TEXT */
    void divide_a_sftext(sfText *text, sfVector2f pos, rpg_t *rpg);
    void divide_a_text(rpg_t *rpg, char *str, sfVector2f pos, sfColor color);


    /* CALL ACTIONS */
    void go_to_annia(void *main);
    void npc_give_food(void*);
    void little_girl(rpg_t *rpg, sfVector2f pos);
    void inte_test(rpg_t *rpg);
    void i_house_door(rpg_t *rpg, sfVector2f pos);
    void i_house_paper(rpg_t *rpg, sfVector2f pos);
    void i_chest(rpg_t *rpg);
    interactions_t *get_interactions_array(void);
    void draw_interaction_popup(
        rpg_t *rpg,
        sfVector2f pos,
        sfKeyCode key,
        char *str
    );

    /* LORE */
    void draw_popup_lore(rpg_t *rpg);
    void check_popup_lore(rpg_t *rpg);

    /* FPS */
    void print_framerate(void);

    /* EVENTS */
    void e_key_released(window_t *window, void *main);
    void e_key_pressed(window_t *window, void *main);
    void e_open_inventory(window_t *window, void *main);
    void e_close(window_t *window, void *main);
    void e_dialogue(window_t *window, void *main);

    /* INIT */
    void init(rpg_t *rpg);
    void init_quests(rpg_t *rpg);
    void init_player(rpg_t *rpg);
    void init_popup_dialogue(rpg_t *rpg);
    void init_glib(rpg_t *rpg);
    void init_npcs(map_t *map, char *path, rpg_t *rpg);
    void init_fonts(rpg_t *rpg);
    void init_player_textures(player_t *player);
    void init_window(rpg_t *rpg);
    void init_npc_dialogs(npc_t *npc, parsed_data_t *dialogs_arr, rpg_t *rpg);
    void init_settings(rpg_t *rpg);
    void init_sounds(GLib_t *glib);
    void init_language(rpg_t *rpg);
    void init_popup_lore(rpg_t *rpg);
    void init_save(rpg_t *rpg);
    void init_events(rpg_t *rpg);
    void init_player_assets(player_t *player);
    void init_rpg(rpg_t *rpg, int ac, char **av);
    void init_popup_interaction(rpg_t *rpg);
    void init_player_items_packs(player_t *player);
    void init_quest_assets(rpg_t *rpg);
    void init_inventory(rpg_t *rpg);
    void init_player_assets_dialogue(player_t *player);

#endif
