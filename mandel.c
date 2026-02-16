#include "header.h"

double x_to_complex_plan(int px, int width, double min_x, double max_x)
{
  return min_x + ((double)px / (width - 1)) * (max_x - min_x);
}

double y_to_complex_plan(int py, int height, double min_y, double max_y)
{
  return max_y - ((double)py / (height - 1)) * (max_y - min_y);
}

// Valeur appartenant a l'intervalle imin, imax
void fractol(t_mlx *mlx, t_point pixel)
{
  t_point z;
  t_point temp;
  // int  iteration_count[WIDTH][HEIGHT];
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
    if (temp.x_com + temp.y_com > 2*2)
        break;
    temp.x_com = z.x_com * z.x_com;
    temp.y_com = z.y_com * z.y_com;
    z.y_com = 2 * z.x_com * z.y_com + pixel.y_com;
    z.x_com = temp.x_com - temp.y_com + pixel.x_com;
    iteration++;
  }
  if (iteration == MAX_ITERATION)
    put_pixel(mlx->img_ptr, pixel.x, pixel.y, 0xFFFFFFFF);
  // iteration_count[pixel.x][pixel.y] = iteration;
  // if (pixel.y == HEIGHT -1 && pixel.x == WIDTH -1)
  //   build_histogram(iteration_count);
}

int get_total_iteration(int histogram[MAX_ITERATION])
{
  int total = 0;
  int i = 0;

  while (i < MAX_ITERATION)
  {
    total += histogram[i];
    i++;
  }
  return (total);
}

void  build_histogram(int iteration_count[WIDTH][HEIGHT])
{
  int x;
  int y;
  int i;
  int histogram[MAX_ITERATION];

  x = 0;
  i = 0;
  while (x < WIDTH)
  {
    y = 0;
    while (y < HEIGHT)
    {
      i = iteration_count[x][y];
      histogram[i]++;
      y++;
    }
    x++;
  }
  get_color(get_total_iteration(histogram));
}

void  get_color(int total_iteration)
{
  printf("%d\n", total_iteration);
}

void  for_each_pixel(t_mlx *mlx, void (*f)(t_mlx *, t_point point))
{
  t_point point;

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
}
