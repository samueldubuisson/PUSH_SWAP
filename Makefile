NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ibonus

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
	src/parsing/ft_parse_arguments.c\
	src/parsing/ft_parse_numbers.c\
	src/parsing/ft_check_duplicates.c\
	src/parsing/ft_check_int_limits.c\
	src/utils/ft_utils.c\
	src/parsing/ft_parse_options.c\
	src/utils/ft_utils_list.c\
	src/parsing/ft_print_benchmark.c\
	src/sorting/ft_compute_disorder.c\
	src/sorting/ft_sort_stack.c\
	src/sorting/sort_simple/ft_sort_simple.c\
	src/sorting/sort_medium/ft_sort_medium.c\
	src/sorting/sort_complex/ft_sort_complex.c\
	src/utils/ft_utils_list_two.c\
	src/sorting/sort_simple/ft_find_best_candidate.c\
	src/sorting/sort_simple/ft_rotate_both.c\
	src/sorting/sort_simple/ft_calculate_rotation.c\
	src/parsing/ft_parse_input.c\
	src/sorting/ft_sort_five.c\

BONUS_SRCS = bonus/main.c\
		bonus/ft_checker.c\
		bonus/ft_check_sorted.c\
		$(filter-out src/main.c,$(SRCS))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
