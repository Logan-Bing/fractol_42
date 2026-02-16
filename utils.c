#include "header.h"

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

double x_to_complex_plan(int px, int width, double min_x, double max_x)
{
  return min_x + ((double)px / (width - 1)) * (max_x - min_x);
}

double y_to_complex_plan(int py, int height, double min_y, double max_y)
{
  return max_y - ((double)py / (height - 1)) * (max_y - min_y);
}
