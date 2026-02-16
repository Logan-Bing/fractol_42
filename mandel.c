#include "header.h"

// Valeur appartenant a l'intervalle imin, imax
void fractol(t_mlx *mlx, t_point pixel)
{
  t_point z;
  t_point temp;
  int     iteration;

  z.x_com = 0.0;
  z.y_com = 0.0;
  temp.x_com = 0.0;
  temp.y_com = 0.0;
  iteration = 0;
  pixel.x_com = x_to_complex_plan(pixel.x, WIDTH, -2.00, 0.47);
  pixel.y_com = y_to_complex_plan(pixel.y, HEIGHT, -1.12, 1.12);
  while (iteration < MAX_ITERATION)
  {
    temp.x_com = z.x_com * z.x_com;
    temp.y_com = z.y_com * z.y_com;
    if (temp.x_com + temp.y_com > 4.0)
        break;
    z.y_com = 2 * z.x_com * z.y_com + pixel.y_com;
    z.x_com = temp.x_com - temp.y_com + pixel.x_com;
    iteration++;
  }
  pixel.iteration_count[pixel.x][pixel.y] = iteration;
  if (pixel.y == HEIGHT -1 && pixel.x == WIDTH -1)
  {
    // print_2d_tab(pixel.iteration_count);
    build_histogram(pixel.iteration_count, mlx);
  }
}

void print_2d_tab(int **tab)
{
  for (int i = 0;  i < WIDTH; i++){
    for (int j = 0; j < HEIGHT; j++){
      printf("x :[%d] | j: [%d] | value: [%d]\n", i, j, tab[i][j]);
    }
  }
}

void  for_each_pixel(t_mlx *mlx, void (*f)(t_mlx *, t_point point))
{
  t_point point;

  point.iteration_count = malloc(sizeof(int *) * WIDTH);
  if (!point.iteration_count)
    exit(1);
  for (int i = 0; i < WIDTH; i++){
    point.iteration_count[i] = malloc(sizeof(int) * HEIGHT);
    memset(point.iteration_count[i], 0, sizeof(int) * HEIGHT);
    if (!point.iteration_count[i])
      exit(1);
  }
  point.y = 0;
  while (point.y < HEIGHT)
  {
    point.x = 0;
    while (point.x < WIDTH)
    {
      f(mlx, point);
      point.x++;
    }
    point.y++;
  }
  for (int i = 0; i < WIDTH; i++) {
    free(point.iteration_count[i]);
  } 
  free(point.iteration_count);
}
