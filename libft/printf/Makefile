NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INCS		= -I includes

SRCS		= srcs/ft_printf.c \
			  srcs/ft_parse.c \
			  srcs/ft_print_char.c \
			  srcs/ft_print_str.c \
			  srcs/ft_print_ptr.c \
			  srcs/ft_print_int.c \
			  srcs/ft_print_uint.c \
			  srcs/ft_print_hex.c \
			  srcs/ft_print_percent.c \
			  srcs/ft_utils.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
