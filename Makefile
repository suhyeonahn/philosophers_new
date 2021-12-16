NAME = philo

NAME_BONUS = philo_bonus

SRC = main.c \
		checker.c \
		ft_atoi.c \
		init.c \
		parse.c \
		print.c

SRC_BONUS = main_bonus.c \
				checker_bonus.c \
				ft_atoi_bonus.c \
				init_bonus.c \
				parse_bonus.c \
				print_bonus.c \
				wait_bonus.c

INC_HEADER = includes

DIR_S = srcs

SRCS = $(addprefix ${DIR_S}/, ${SRC})

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

INC_HEADER_BONUS = includes_bonus

DIR_S_BONUS = srcs_bonus

SRCS_BONUS = $(addprefix ${DIR_S_BONUS}/, ${SRC_BONUS})

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INC_HEADER)

$(NAME_BONUS) :	$(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -I$(INC_HEADER_BONUS)
all	: $(NAME)

bonus :  $(NAME_BONUS)

clean	:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean	: clean
			rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: re clean fclean all