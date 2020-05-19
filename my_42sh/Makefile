##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make library
##

SRC	=	$(wildcard *.c) \
		$(wildcard printing/*.c) \
		$(wildcard command_execution/*.c) \
		$(wildcard built_in/*.c) \
		$(wildcard operator/*.c) \
		$(wildcard entry_commands_treatment/*.c) \
		$(wildcard tools/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

UNITTEST_NAME	=	unittest

GREEN	=	\033[0;32m

YELLOW	=	\033[0;33m

NC	=	\033[0m

SPECIAL_FLAG = -Wall -Wextra -Werror

all:	$(OBJ)
	@gcc -o $(NAME) $(SRC) main/main.c -lm -g
	@echo -e "${GREEN}-COMPILATION DONE-${NC}"

run:	$(OBJ)
	@gcc -o $(NAME) $(SRC) main/main.c -lm
	@./$(NAME)

run_vg:	$(OBJ)
	@gcc -o $(NAME) $(SRC) main/main.c -lm -g
	@valgrind ./$(NAME)

tests_run:	$(OBJ)
	@gcc -o $(UNITTEST_NAME) $(SRC) main/unittest.c -lm -lcriterion -fprofile-arcs -ftest-coverage
	@./unittest > /dev/null
	@rm $(UNITTEST_NAME)

tests_run_covr:	$(OBJ)
	@gcc -o $(UNITTEST_NAME) $(SRC) main/unittest.c -lm -lcriterion -fprofile-arcs -ftest-coverage
	@./unittest
	@gcovr
	@rm -f *.gcda *.gcno
	@rm $(UNITTEST_NAME)

tests_run_vg:	$(OBJ)
	@gcc -o $(UNITTEST_NAME) $(SRC) main/unittest.c -lm -lcriterion -g
	@valgrind ./$(UNITTEST_NAME)
	@rm $(UNITTEST_NAME)

clean:
	@rm -f $(OBJ) *.gcda *.gcno
	@echo -e "${YELLOW}-CLEANED-${NC}"

fclean:	clean
	@rm -f $(NAME)
	@echo -e "${YELLOW}-FCLEANED-${NC}"

re:	fclean all

donald:
	@echo -e "${YELLOW}"
	@echo -e "               §§§§             §§§§"
	@echo -e "            §§§    §§§§     §§§§    §§§\n"
	@echo -e "          §§§§       §§§   §§§       §§§\n"
	@echo -e "        §§§§§        §§§§§§§§§        §§§§\n"
	@echo -e "       §§§§§          §§§§§§§          §§§§\n"
	@echo -e "       §§§§            §§§§§           §§§§§\n"
	@echo -e "      §§§§§            §§§§§            §§§§§\n"
	@echo -e "      §§§§§            §§§§§            §§§§§\n"
	@echo -e "      §§§§§                             §§§§§${NC}\n"
