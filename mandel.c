#include "header.h"

double get_complex_position(int x)
{
  double c;

  c = -2.0 + ((double)x / (WIDTH - 1)) * (0.47 - (-2.00));
  return c;
}

// Valeur appartenant a l'intervalle imin, imax
void fractol(t_mlx *mlx, int px, int py)
{
  t_complex z;
  t_complex c;
  double    xtemp;
  int       iteration;

  c.real = -2.0 + ((double)px / (WIDTH - 1)) * (0.47 - (-2.00));
  c.im = 1.12 - ((double)py / (HEIGHT - 1)) * (1.12 - (-1.12));
  z.real = 0.0;
  z.im = 0.0;
  iteration = 0;
  while (iteration < MAX_ITERATION)
  {
    if (z.real * z.real + z.im * z.im > 2*2)
        break;
    xtemp = z.real * z.real - z.im * z.im + c.real;
    z.im = 2 * z.real * z.im + c.im;
    z.real = xtemp;
    iteration++;
  }
  if (iteration == MAX_ITERATION)
    put_pixel(mlx->img_ptr, px, py, 0xFFFFFFFF);
}

void  for_each_pixel(t_mlx *mlx, void (*f)(t_mlx *, int, int))
{
  t_point point;

  point.y = 0;
  point.x = 0;
  while (point.y < HEIGHT)
  {
    point.x = 0;
    while (point.x < WIDTH)
    {
      f(mlx, point.x, point.y);
      point.x++;
    }
    point.y++;
  }
}
