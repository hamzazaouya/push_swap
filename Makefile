NAME = push_swap
SRCS = src/push_swap.c includes/ft_atoi.c includes/ft_strcmp.c src/stacks.c src/rules1.c src/rules2.c src/rules3.c src/function1.c src/push_atb.c
OBJ_PATH  = objs
CC = cc

SRCS_OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS_OBJS)
	$(CC) $(SRCS) -o $(NAME)
clean:
	rm -f $(SRCS_OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all