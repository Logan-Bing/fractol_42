NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c \
			 hook.c \
			 mandel.c \
			 utils.c \
			 color_algo.c \
			 mlx_init.c
LIBFT_DIR = libft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx_linux
MLX_LIB = mlx_Linux

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) -l$(MLX_LIB) -L$(LIBFT_DIR) -lft -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(LIBFT)
	$(CC) $(FLAGS) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all
