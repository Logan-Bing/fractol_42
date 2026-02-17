#include "header.h"

// Valeur appartenant a l'intervalle imin, imax
void fractol(t_mlx *mlx, t_point pixel) {
  t_point z;
  t_point temp;
  int iteration;

  z.x_com = x_to_complex_plan(pixel, -2.00, 0.47);
  z.y_com = y_to_complex_plan(pixel, -1.12, 1.12);
  temp.x_com = 0.0;
  temp.y_com = 0.0;
  iteration = 0;
  pixel.x_com = -0.8;
  pixel.y_com = 0.156;
  while (iteration < MAX_ITERATION) {
    temp.x_com = z.x_com * z.x_com;
    temp.y_com = z.y_com * z.y_com;
    if (temp.x_com + temp.y_com > 4.0)
      break;
    z.y_com = 2 * z.x_com * z.y_com + pixel.y_com;
    z.x_com = temp.x_com - temp.y_com + pixel.x_com;
    iteration++;
  }
  pixel.iteration_count[pixel.x][pixel.y] = iteration;
  if (pixel.y == HEIGHT - 1 && pixel.x == WIDTH - 1) {
    build_histogram(pixel.iteration_count, mlx);
  }
}

// void print_2d_tab(int **tab) {
//   for (int i = 0; i < WIDTH; i++) {
//     for (int j = 0; j < HEIGHT; j++) {
//       printf("x :[%d] | j: [%d] | value: [%d]\n", i, j, tab[i][j]);
//     }
//   }
// }

int **init_iteration_count(void) {
  int **iteration_count;
  int i;

  i = 0;
  iteration_count = malloc(sizeof(int *) * WIDTH);
  if (!iteration_count)
    return (NULL);
  while (i < WIDTH) {
    iteration_count[i] = malloc(sizeof(int) * HEIGHT);
    if (!iteration_count[i])
      return (NULL);
    i++;
  }
  return (iteration_count);
}

void for_each_pixel(t_mlx *mlx, double scale,
                    void (*f)(t_mlx *, t_point point)) {
  t_point data;

  data.zoom = 1.00 + scale;
  data.iteration_count = init_iteration_count();
  data.y = 0;
  while (data.y < HEIGHT) {
    data.x = 0;
    while (data.x < WIDTH) {
      f(mlx, data);
      data.x++;
    }
    data.y++;
  }
  // TODO: Put this in free double tab function
  for (int i = 0; i < WIDTH; i++) {
    free(data.iteration_count[i]);
  }
  free(data.iteration_count);
}
