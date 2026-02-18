#include "header.h"
#include "libft/libft.h"

void put_pixel(t_img *img, int x, int y, int color) {
  char *dst;

  dst = img->img_pixel + (y * img->line_length + x * (img->bpp / 8));
  *(unsigned int *)dst = color;
}

void display_available_params(void) {
  ft_printf("---PARAMS---\n");
  ft_printf("- ./mandel\n");
  ft_printf("- ./julia -x -y\n");
  ft_printf("exemple of set for julia: x:0.3 y:0.5 ");
}

void *parse_args(int argc, char *argv[], t_mlx *mlx) {
  if (argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen("julia"))) {
    mlx->julia_x = ft_atod(argv[2]);
    mlx->julia_y = ft_atod(argv[3]);
    return (&init_julia_set);
  }
  if (argc == 2 && !ft_strncmp(argv[1], "mandel", ft_strlen("mandel"))) {
    return (&init_mandelbrot_set);
  }
  display_available_params();
  return (NULL);
}

int main(int argc, char *argv[]) {
  t_mlx *mlx;
  void *chosen_func;

  mlx = init_deps();
  chosen_func = parse_args(argc, argv, mlx);
  if (!chosen_func)
    exit(1);
  mlx->set_func = chosen_func;
  for_each_pixel(mlx, 0.0);
  mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img_ptr->img, 0,
                          0);
  mlx_hook(mlx->window, DESTROY_NOTIFY, 0, close_window, mlx);
  mlx_key_hook(mlx->window, keypress, mlx);
  mlx_mouse_hook(mlx->window, mouse_hook, mlx);
  mlx_loop(mlx->connection);
}
