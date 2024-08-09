NAME = push_swap.a

PUSHSWAP = src/push_swap.c utils/push_swap_utils.c \
	src/checker.c utils/t_list_utils.c src/big_sort.c \
	utils/simplify.c utils/42_functions.c utils/do_reverse_rotate.c \
	utils/do_rotate.c src/small_sort.c \

PRINTF = printf

SRCS = ${PUSHSWAP}

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -I ./

.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ${PRINTF}
	cp ./$(PRINTF)/libftprintf.a ./$(NAME)
	ar -rc ${NAME} ${OBJS}
	ranlib $(NAME)
	${CC} ${CFLAGS} ${NAME} -o push_swap 

all: ${NAME}

clean:
	/bin/rm -f $(OBJS) $(DEPS)
	make clean -C $(PRINTF)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}