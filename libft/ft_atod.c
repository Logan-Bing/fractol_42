#include "libft.h"

// TODO: Norm this fcking file
static double divide_n_times(char *str) {
  int len;
  int n;
  double res;

  res = 0;
  len = ft_strlen(str);
  n = atoi(str);
  res = (double)n;
  while (len--) {
    res = res / 10;
  }
  return (res);
}

void free_2d_tab(char **str) {
  int i = 0;
  while (str[i]) {
    free(str[i]);
    i++;
  }
  free(str);
}

double ft_atod(char *str) {
  char **splitted;
  double res;
  double dec_part;
  int ent_part;

  splitted = ft_split(str, '.');
  ent_part = ft_atoi(splitted[0]);
  dec_part = divide_n_times(splitted[1]);
  if (ent_part < 0)
    res = ent_part - dec_part;
  else
    res = ent_part + dec_part;
  free_2d_tab(splitted);
  if (*str == '-')
    return (res * -1);
  return (res);
}
