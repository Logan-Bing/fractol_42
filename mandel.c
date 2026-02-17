#include "header.h"

void	init_julia_set(t_point *z, t_point *pixel, t_point julia_set)
{
	pixel->x_com = julia_set.x_com;
	pixel->y_com = julia_set.y_com;
	z->x_com = x_to_complex_plan(*pixel, -2.00, 0.47);
	z->y_com = y_to_complex_plan(*pixel, -1.12, 1.12);
}

void	init_mandelbrot_set(t_point *z, t_point *pixel, t_point julia_set)
{
	(void)julia_set;
	pixel->x_com = x_to_complex_plan(*pixel, -2.00, 0.47);
	pixel->y_com = y_to_complex_plan(*pixel, -1.12, 1.12);
	z->x_com = 0;
	z->y_com = 0;
}

void	fractol(t_mlx *mlx, t_point pixel, t_point julia_set,
		void (*f)(t_point *, t_point *, t_point))
{
	t_point	z;
	t_point	temp;
	int		iteration;

	f(&z, &pixel, julia_set);
	temp.x_com = 0.0;
	temp.y_com = 0.0;
	iteration = 0;
	while (iteration < MAX_ITERATION)
	{
		temp.x_com = z.x_com * z.x_com;
		temp.y_com = z.y_com * z.y_com;
		if (temp.x_com + temp.y_com > 4.0)
			break ;
		z.y_com = 2 * z.x_com * z.y_com + pixel.y_com;
		z.x_com = temp.x_com - temp.y_com + pixel.x_com;
		iteration++;
	}
	pixel.iteration_count[pixel.x][pixel.y] = iteration;
	if (pixel.y == HEIGHT - 1 && pixel.x == WIDTH - 1)
	{
		build_histogram(pixel.iteration_count, mlx);
	}
}

int	**init_iteration_count(void)
{
	int	**iteration_count;
	int	i;

	i = 0;
	iteration_count = malloc(sizeof(int *) * WIDTH);
	if (!iteration_count)
		return (NULL);
	while (i < WIDTH)
	{
		iteration_count[i] = malloc(sizeof(int) * HEIGHT);
		if (!iteration_count[i])
			return (NULL);
		i++;
	}
	return (iteration_count);
}

void	clear_2d_tab(int **tab)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	for_each_pixel(t_mlx *mlx, double scale)
{
	t_point	data;

	data.zoom = 1.00 + scale;
	data.iteration_count = init_iteration_count();
	data.y = 0;
	while (data.y < HEIGHT)
	{
		data.x = 0;
		while (data.x < WIDTH)
		{
			fractol(mlx, data, data, mlx->set_func);
			data.x++;
		}
		data.y++;
	}
	clear_2d_tab(data.iteration_count);
}
