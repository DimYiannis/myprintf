CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =  ft_printf.c header.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = print_%_bonus.c print_char_bonus.c print_hex_bonus.c print_int_bonus.c \
print_pointer_bonus.c print_string_bonus.c print_uint_bonus.c ft_printf_bonus.c \
ft_printf_bonus.h
BONUS_OBJ = $(BONUS_SRC):.c=.o	

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

bonu: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus