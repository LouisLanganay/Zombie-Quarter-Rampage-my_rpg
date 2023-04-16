##
## EPITECH PROJECT, 2023
## glib
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = libgl.a


VPATH := ./window
VPATH += ./events
VPATH += ./sprites
VPATH += ./sounds
VPATH += ./texts
VPATH += ./buttons
VPATH += ./scenes
VPATH += ./fonts
VPATH += ./dropdown

vpath %.c $(VPATH)

SRC := gl_create_window.c
SRC += gl_create_event.c
SRC += gl_check_events.c
SRC += gl_create_sprite.c
SRC += gl_draw_sprites.c
SRC += gl_draw_sprite.c
SRC += gl_delete_sprite.c
SRC += gl_delete_sprites.c
SRC += gl_create_text.c
SRC += gl_delete_text.c
SRC += gl_delete_texts.c
SRC += gl_draw_text.c
SRC += gl_draw_texts.c
SRC += gl_create_button.c
SRC += gl_draw_button.c
SRC += gl_buttons_hovered.c
SRC += gl_button_change_state.c
SRC += gl_add_button_to_scene.c
SRC += gl_create_scene.c
SRC += gl_draw_scene.c
SRC += gl_create_font.c
SRC += gl_delete_font.c
SRC += gl_delete_fonts.c
SRC += gl_get_font.c
SRC += gl_create_ddown.c
SRC += gl_draw_ddown.c
SRC += gl_add_child_ddown.c
SRC += gl_ddowns_hovered.c
SRC += gl_get_text.c
SRC += gl_ddown_draw_childs.c
SRC += gl_create_sound.c
SRC += gl_get_sound.c
SRC += gl_play_sound.c
SRC += gl_get_button.c



INC_DIR := ../../includes
INC_NAME := gl.h
BUILD_DIR = build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)
	@ echo -e "${_B_GREEN}[SUCCES]${_END} Compilation done"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(@D)
	@ $(CC) -g $(LIBFLAGS) -c $< -o $@
	@ echo -e "${_CYAN}[OK]$(_END) -> $(CC)    $(_U_WHITE)$<$(_END)"

$(NAME): $(OBJ) $(SRC)
	@ mkdir -p $(BUILD_DIR)
	@ ar rc $(NAME) $(OBJ)
	@ echo -e "${_CYAN}[OK]$(_END) -> $(AR)    $(_U_WHITE)$(NAME)${_END}"
	@ cp ${INC_NAME} ${INC_DIR}
	@ echo -e "${_CYAN}[OK]$(_END) -> cp      $(_U_WHITE)${INC_NAME}$(_END) \
	$(_U_WHITE)${INC_DIR}${_END}"

clean:
	@ $(RM) *.gcda
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcda${_END}"
	@ $(RM) *.gcno
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    *.gcno${_END}"
	@ $(RM)	$(OBJ)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(OBJ)${_END}"
	@ echo -e "${_B_BLUE}[CLEAN]${_END} Clean done"

fclean: clean
	@ $(RM) -r $(BUILD_DIR)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(BUILD_DIR)${_END}"
	@ $(RM)	$(NAME)
	@ echo -e "${_BLACK}${_BB_WHITE}-> $(RM)    $(NAME)${_END}"
	@ echo -e "${_B_BLUE}[FCLEAN]${_END} Fclean done"

re: fclean all

.PHONY: clean fclean re
