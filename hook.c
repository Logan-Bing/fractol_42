#include "header.h"

int  keypress(int keycode, t_mlx *mlx)
{
  if (keycode == ESC_CODE)
  {
    clean_mlx(mlx);
    exit(EXIT_CLEAN);
  }
  return 0;
}

int close_window(t_mlx *mlx)
{
    clean_mlx(mlx);
    exit(EXIT_CLEAN);
}

int  mouse_hook(int button, int x, int y, t_mlx *mlx)
{
  (void)mlx;
  printf("%d\n", button);
  printf("x :%d\n", x);
  printf("y :%d\n", y);
  return (1);
}

void  clean_mlx(t_mlx *mlx)
{
    mlx_destroy_window(mlx->connection, mlx->window);
    mlx_destroy_image(mlx->connection, mlx->img_ptr->img);
    mlx_destroy_display(mlx->connection);
    if (mlx->img_ptr)
      free(mlx->img_ptr);
    if (mlx->connection)
      free(mlx->connection);
    if (mlx)
      free(mlx);
}
