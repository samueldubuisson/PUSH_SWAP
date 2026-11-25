
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c\
 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF_DIR = ./printf
PRINTF_SRC = $(addprefix $(PRINTF_DIR)/srcs/, ft_printf.c ft_parse.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_percent.c ft_print_ptr.c ft_print_str.c ft_print_uint.c ft_utils.c)

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS)
	ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS)

$(PRINTF_DIR)/srcs/%.o: $(PRINTF_DIR)/srcs/%.c
	$(CC) $(CFLAGS) -I. -I$(PRINTF_DIR)/includes -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

