NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT = libft/libft.a

SRCS = src/main.c\
	src/operations/swap.c\
	src/operations/push.c\
	src/operations/rotate.c\
	src/operations/reverse_rotate.c\
	src/operations/instructions/sa.c\
	src/operations/instructions/sb.c\
	src/operations/instructions/ss.c\
	src/operations/instructions/pa.c\
	src/operations/instructions/pb.c\
	src/operations/instructions/ra.c\
	src/operations/instructions/rb.c\
	src/operations/instructions/rr.c\
	src/operations/instructions/rra.c\
	src/operations/instructions/rrb.c\
	src/operations/instructions/rrr.c\
	src/parsing/ft_fill_stack.c\
	src/parsing/ft_init_struct.c\
	src/parsing/free_parse.c\
	src/parsing/ft_parse_arguments.c\
	src/parsing/ft_parse_numbers.c\
	src/parsing/ft_check_duplicates.c\
	src/parsing/ft_check_int_limits.c\
	src/parsing/ft_strcmp.c\
	src/parsing/ft_parse_options.c\
	src/utils/ft_utils_list.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
