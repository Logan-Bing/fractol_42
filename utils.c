#include "header.h"

int get_total_iteration(int histogram[MAX_ITERATION]) {
  int total = 0;
  int i = 0;

  while (i < MAX_ITERATION) {
    total += histogram[i];
    i++;
  }
  return (total);
}

double x_to_complex_plan(t_point pixel, double min_x, double max_x) {
  return (min_x + ((double)pixel.x / (WIDTH - 1)) * (max_x - min_x)) /
         pixel.zoom;
}

double y_to_complex_plan(t_point pixel, double min_y, double max_y) {
  return (max_y - ((double)pixel.y / (HEIGHT - 1)) * ((max_y - min_y))) /
         pixel.zoom;
}
