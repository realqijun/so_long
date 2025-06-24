CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ./includes
RM = rm -rf
NAME = so_long
# FSAN = -g3 -fsanitize=address

SL_UTIL_DIR = ./so_long_utils/
SL_C = ft_check_objectives.c \
			ft_check_playable.c \
			ft_error.c \
			ft_handle_input.c \
			ft_init.c \
			ft_read_map.c \
			ft_render_map.c

SL_UTILS = $(addprefix $(SL_UTIL_DIR),$(SL_C))

LIBFT = -I $(INC)/libft -L $(INC)/lifbt -lft
FT_PRINTF = -I $(INC)/ft_printf -L $(INC)/ft_printf -lftprintf
MLX = -I $(INC)/minilibx -L $(INC)/minilibx -lmlx -framework AppKit -framework OpenGL
GNL_DIR = $(INC)/get_next_line
GNL_FILES = $(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c
LIBFT_A = $(INC)/libft/libft.a
LIBFTPRINTF_A = $(INC)/ft_printf/libftprintf.a


all: $(NAME) 

$(NAME): $(SL_O)
	make -C ./includes/minilibx
	make -C ./includes/ft_printf
	make -C ./includes/libft
	$(CC) $(CFLAGS) $(MLX) $(NAME).c $(SL_UTILS) $(LIBFT_A) $(LIBFTPRINTF_A) $(GNL_FILES) -o $(NAME)


# debug: 
# 	make -C ./includes/minilibx
# 	make -C ./includes/ft_printf
# 	make -C ./includes/libft
# 	$(CC) $(CFLAGS) $(FSAN) $(MLX) $(NAME).c $(SL_UTILS) -g $(LIBFT_A) $(LIBFTPRINTF_A) $(GNL_FILES) -o $(NAME)

clean:
	make clean -C $(INC)/libft
	make clean -C $(INC)/ft_printf
	make clean -C $(INC)/minilibx

fclean: clean
	make fclean -C $(INC)/libft
	make fclean -C $(INC)/ft_printf
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
