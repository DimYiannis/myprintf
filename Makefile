CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =  ft_printf.c header.c
OBJ = $(SRC:.c=.o)
	
%.o: %.c myheader.h
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)	

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus