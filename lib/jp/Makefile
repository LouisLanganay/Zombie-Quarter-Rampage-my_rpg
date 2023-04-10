##
## EPITECH PROJECT, 2023
## json-parser
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = libjp.a


VPATH := reader
VPATH += utils
VPATH += writer
VPATH += writer/type
VPATH += reader/loaders
VPATH += reader/search
VPATH += reader/getvalue

vpath %.c $(VPATH)

SRC := main_reader.c
SRC += my_strlen.c
SRC += my_nbrlen.c
SRC += my_strcmp.c
SRC += my_getnbr_float.c
SRC += my_compute_power_rec.c
SRC += load_file_in_str.c
SRC += jp_skipspaces.c
SRC += jp_getvalue_string.c
SRC += jp_getvalue_int.c
SRC += jp_getvalue.c
SRC += jp_getvalue_bool.c
SRC += jp_search.c
SRC += jp_search_tools.c
SRC += load_array.c
SRC += load_object.c
SRC += my_getnbr.c
SRC += main_writer.c
SRC += jp_writestr.c
SRC += jp_writedata.c
SRC += jp_writedata_name.c
SRC += jp_writedata_value.c
SRC += jp_writeint.c
SRC += jp_writebool.c
SRC += jp_writetab.c
SRC += jp_writearray.c
SRC += my_is_a_float.c


INC_DIR := ../../includes
INC_NAME := jp.h
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
