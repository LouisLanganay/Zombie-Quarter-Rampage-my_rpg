##
## EPITECH PROJECT, 2023
## json-parser
## File description:
## Makefile
##

include Makefile_colors.mk

NAME = unit_tests

TESTS_FILES := main.c

LIB_DIR := ../lib/jp
LIB_NAME := jp

INC_DIR := ../includes
FLAGS = --coverage -lcriterion -I${INC_DIR} -L${LIB_DIR} -l${LIB_NAME}

all: $(NAME) clean
	@ echo "Compilation done"

$(NAME): $(SRC)
	@ mkdir -p ../includes
	@ make re -C ../lib/jp
	@ echo ${SRC} ${TESTS_FILES}
	@ gcc -o ${NAME} ${SRC} ${TESTS_FILES} ${FLAGS}
	@ echo -e "${_B_GREEN}[SUCCES]${_END} Compilation done"

run_tests: fclean all
	@ cp do_not_modify.json tests.json
	@ ./$(NAME)
	@ gcovr --exclude tests
	@ echo -e "${_B_GREEN}[SUCCES]${_END} Run tests done"

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM)	$(OBJ)
	@ echo -e "${_B_RED}[CLEAN]${_END} Clean done"

fclean: clean
	@ make fclean -C ../lib/jp
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM)	$(NAME)
	@ $(RM) coverage.xml
	@ echo -e "${_B_RED}[FCLEAN]${_END} Fclean done"

re: fclean all

.PHONY: clean fclean re
