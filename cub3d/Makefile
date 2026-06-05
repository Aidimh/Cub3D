# **************************************************************************** #
#                                   CUB3D                                      #
# **************************************************************************** #

NAME = cub3D
CC = cc
LIBFT_DIR = libft
CFLAGS = -Wall -Wextra -Werror -I. -Iminilibx-linux
MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
main.c \
free/free.c \
free/free_mlx.c \
error_message/error_messages0.c \
error_message/error_messages1.c \
error_message/error_messages2.c \
error_message/error_messages3.c \
error_message/error_messages4.c \
error_message/error_messages5.c \
error_message/error_messages.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
Parsing_rendering/parse_map.c \
Parsing_rendering/general_parsing_funcs.c \
Parsing_rendering/parse_map_directions.c \
Parsing_rendering/parse_map_rgb.c \
Parsing_rendering/parsing_lines_funcs.c \
Parsing_rendering/check_map_file.c \
Parsing_rendering/map_padding.c \
Parsing_rendering/walls_check.c \
Parsing_rendering/validate_map.c \
Parsing_rendering/validate_textures_lines.c \
Raycasting/drawing.c \
Raycasting/map_elements.c \
Raycasting/moves.c \
Raycasting/dda.c \
Raycasting/drawing_utils.c \
Raycasting/moves_utils.c

LIBFT_SRCS = libft/ft_atoi.c \
             libft/ft_bzero.c \
             libft/ft_calloc.c \
             libft/ft_isalnum.c \
             libft/ft_isalpha.c \
             libft/ft_isascii.c \
             libft/ft_isdigit.c \
             libft/ft_isprint.c \
             libft/ft_itoa.c \
             libft/ft_lstadd_back_bonus.c \
             libft/ft_lstadd_front_bonus.c \
             libft/ft_lstclear_bonus.c \
             libft/ft_lstdelone_bonus.c \
             libft/ft_lstiter_bonus.c \
             libft/ft_lstlast_bonus.c \
             libft/ft_lstmap_bonus.c \
             libft/ft_lstnew_bonus.c \
             libft/ft_lstsize_bonus.c \
             libft/ft_memchr.c \
             libft/ft_memcmp.c \
             libft/ft_memcpy.c \
             libft/ft_memmove.c \
             libft/ft_memset.c \
             libft/ft_putchar_fd.c \
             libft/ft_putendl_fd.c \
             libft/ft_putnbr_fd.c \
             libft/ft_putstr_fd.c \
             libft/ft_split.c \
             libft/ft_strchr.c \
             libft/ft_strdup.c \
             libft/ft_striteri.c \
             libft/ft_strjoin.c \
             libft/ft_strlcat.c \
             libft/ft_strlcpy.c \
             libft/ft_strlen.c \
             libft/ft_strmapi.c \
             libft/ft_strncmp.c \
             libft/ft_strnstr.c \
             libft/ft_strrchr.c \
             libft/ft_strtrim.c \
             libft/ft_substr.c \
             libft/ft_tolower.c \
             libft/ft_toupper.c \
             libft/ft_strcmp.c \
             libft/ft_strcpy.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩 Compiled: $<"

clean:
	@rm -f $(OBJS) $(LIBFT_OBJS)
	make -C $(LIBFT_DIR) clean
	@echo "🧹 Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "🔥 Removed executable: $(NAME)"

re: fclean all

.PHONY: all clean fclean re