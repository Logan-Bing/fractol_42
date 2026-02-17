#include "header.h"
#include "libft/ft_printf/ft_printf.h"

void put_pixel(t_img *img, int x, int y, int color) {
  char *dst;

  dst = img->img_pixel + (y * img->line_length + x * (img->bpp / 8));
  *(unsigned int *)dst = color;
}

void display_available_params(void) {
  ft_printf("---PARAMS---\n");
  ft_printf("- ./mandelbrot\n");
  ft_printf("- ./julia -set\n");
  ft_printf("exemple of set: [0.3 0.5] ");
}

void *parse_args(int argc, char *argv[]) {
  if (argc < 2 || argc > 3) {
    printf("Need to respect the following format\n");
    display_available_params();
    exit(0);
  } else if (argc == 3) {
    // TODO: parse for julia
  }
  return (&init_mandelbrot_set);
  (void)argv;
}

int main(int argc, char *argv[]) {
  t_mlx *mlx;

  parse_args(argc, argv);
  mlx = init_deps();
  mlx->set_func = &init_mandelbrot_set;
  for_each_pixel(mlx, 0.0);
  mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img_ptr->img, 0,
                          0);
  mlx_hook(mlx->window, DESTROY_NOTIFY, 0, close_window, mlx);
  mlx_key_hook(mlx->window, keypress, mlx);
  mlx_mouse_hook(mlx->window, mouse_hook, mlx);
  mlx_loop(mlx->connection);
}
