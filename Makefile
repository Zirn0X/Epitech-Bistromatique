##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## Makefile of the project
##

MAIN	=	main.c
SRC	=	check_args.c		\
		input_reader.c		\
		translator.c		\
		error.c			\
		check_expression.c	\
		eval_expr.c		\
		bistromatic.c		\

TST	=	tests/test_check_args.c		\
		tests/test_translator.c		\
		tests/test_check_expression.c	\
		tests/test_eval_expr.c		\
		tests/test_error.c		\
		tests/test_input_reader.c	\
		tests/test_bistromatic.c	\

NAME	=	calc
BARGS	=	-Wall -Wextra -Iinclude -Llib/my -lmy
TARGS	=	-lcriterion --coverage

all: $(NAME)

$(NAME):	build_lib
	gcc $(SRC) $(MAIN) -o $(NAME) $(BARGS)

clean:
	@find . \( -name "#*#" -o -name "*~" -o -name "*.o" \
	-o -name "*.gcda" -o -name "*.gcno" \) -delete

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME).test

build_lib:
	cd lib/my && ./build.sh

tests_run:	build_lib fclean $(TST)
	gcc $(SRC) $(TST) -o $(NAME).test $(BARGS) $(TARGS)
	./$(NAME).test
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

re:	fclean all