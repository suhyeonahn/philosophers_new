NAME = philo

SRC = main.c \
		checker.c \
		ft_atoi.c \
		init.c \
		parse.c \
		print.c

INC_HEADER = includes

DIR_S = srcs

SRCS = $(addprefix ${DIR_S}/, ${SRC})

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INC_HEADER)

all	: $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	: clean
			rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean all