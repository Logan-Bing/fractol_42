#include "header.h"

// Valeur appartenant a l'intervalle imin, imax
void fractol (t_mlx *mlx)
{
  int px = 0;
  int py = 0;
  double xtemp;
  int iteration;
  int max_iteration = 50;

  while (px < WIDTH && py < HEIGHT)
  {
    double x = -2.00 + (double)px / WIDTH * (0.47 - (-2.00));
    double y = 1.12 - (double)py / HEIGHT * (1.12 - (-1.12));
    iteration = 0;
    xtemp = 0.0;
    while ( x*x + y*y < 2.0*2.0 && iteration < max_iteration)
    {
      xtemp += x*x + x;
      y += 2*x*y + y;
      x += xtemp;
      iteration++;
    }
    if (iteration >= max_iteration)
    {
      put_pixel(mlx->img_ptr, px, py, 0xFFFFFFFF);
    }
    py++;
    px++;
  }
}
