NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c color.c hook.c mandel.c utils.c color_algo.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = mlx_linux
MLX_LIB = mlx_Linux

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) -l$(MLX_LIB) -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
