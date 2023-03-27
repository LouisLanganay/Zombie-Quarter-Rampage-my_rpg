##
## EPITECH PROJECT, 2023
## glib
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = rpg
CC = gcc

VPATH := src
VPATH += src/init
VPATH += src/map
VPATH += src/map/load
VPATH += src/map/draw
VPATH += src/utils
VPATH += src/view
VPATH += src/events
VPATH += src/player
VPATH += src/player/moovment
VPATH += src/player/interactions
VPATH += src/player/colisions
VPATH += src/player/interactions/functions

vpath %.c $(VPATH)

SRC := main.c
SRC += my_strcmp.c
SRC += my_strcat.c
SRC += my_strcpy.c
SRC += create_map.c
SRC += load_tiles_textures.c
SRC += load_map_layers.c
SRC += load_layer_data_arr.c
SRC += load_layer_objects.c
SRC += load_tiles_colisions.c
SRC += load_layer_sprites.c
SRC += draw_map.c
SRC += draw_layer.c
SRC += set_view_on_player.c
SRC += init_view.c
SRC += init_player.c
SRC += draw_player.c
SRC += change_player_rect.c
SRC += check_player_moovment.c
SRC += check_colisions.c
SRC += check_interactions.c
SRC += get_interactions_array.c
SRC += inte_test.c
SRC += i_chest.c
SRC += load_tilesets.c
SRC += print_framerate.c
SRC += draw_layer_by_class.c
SRC += draw_layer_by_order.c
SRC += e_key_pressed.c
SRC += init_events.c
SRC += init_glib.c
SRC += init_window.c
SRC += e_key_released.c
SRC += e_close.c

INC_DIR 	:= includes
LIB_DIR1 	:= ./lib/gl
LIB_NAME1 	:= gl
LIB_DIR2 	:= ./lib/jp
LIB_NAME2 	:= jp

CFLAGS = -iquote $(INC_DIR) -Wall -Wextra -Werror -g
CFLAGS += -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio

LIBFLAGS = -L$(LIB_DIR1) -l$(LIB_NAME1) -L$(LIB_DIR2) -l$(LIB_NAME2)

BUILD_DIR = build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

DIE = exit 1
ECHO = echo -e

%.c:
	@ $(ECHO) "${_B_RED}[ERROR]${_END} File ${_B_WHITE}$@${_END} not found."
	@ $(DIE)

all: $(NAME)
	@ $(ECHO) "${_B_GREEN}[SUCCES]${_END} RPG compiled successfully, \
	ready to play!"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@
	@ $(ECHO) "${_CYAN}[OK]$(_END) -> $(CC)    $(_U_WHITE)$<$(_END)"

$(NAME): libs $(OBJ) $(SRC)
	@ mkdir -p $(BUILD_DIR)
	@ $(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)
	@ $(ECHO) "${_CYAN}[OK]$(_END) -> $(CC)    \
	$(_U_WHITE)$(NAME) $(CFLAGS) $(LIBFLAGS)${_END}"
	@ $(ECHO) "$(_B_PURPLE)[STATS]$(_END) -> \
	$(_U_WHITE)$(shell echo "$?" | wc -w) file(s) compiled${_END}."

libs:
	@ make -s -C ${LIB_DIR1}
	@ make -s -C ${LIB_DIR2}

debug: $(CFLAGS) += -g
debug: re

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@ $(RM) coding-style-reports.log
	@ $(RM)	$(OBJ)
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcda${_END}"
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcno${_END}"
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcov${_END}"
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    vgcore.*${_END}"
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    coding-style-reports.log${_END}"
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    $(OBJ)${_END}"

fclean: clean
	@ make fclean -s -C $(LIB_DIR1)
	@ make fclean -s -C $(LIB_DIR2)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM)	$(NAME)
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    $(BUILD_DIR)${_END}"
	@ $(ECHO) "${_BLACK}${_BB_WHITE}-> $(RM)    $(NAME)${_END}"

re: fclean all

.PHONY: clean fclean re
