CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
LINKER = -L $(INCLUDES)/minilibx -L $(INCLUDES)/ft_printf -lmlx -lftprintf
MLX = -I $(INCLUDES)/minilibx $(LINKER) -framework AppKit -framework OpenGL
RM = rm -rf
NAME = so_long

GET_NEXT_LINE_DIR = $(INCLUDES)/get_next_line
GET_NEXT_LINE_FILES = $(GET_NEXT_LINE_DIR)/get_next_line_bonus.c \
			$(GET_NEXT_LINE_DIR)/get_next_line_utils_bonus.c

all:
	make -C ./includes/ft_printf
	cp ./includes/ft_printf/libftprintf.a ./
	make -C ./includes/libft
	cp ./includes/libft/libft.a ./
	$(CC) $(CFLAGS) $(MLX) test.c libft.a libftprintf.a $(GET_NEXT_LINE_FILES) -o $(NAME)

clean:
	make clean -C ./includes/libft
	make clean -C ./includes/ft_printf
	$(RM) $(NAME)

.PHONY: all clean
