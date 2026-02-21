/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:23:06 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 17:26:34 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_julia_set(t_point *z, t_point *pixel, t_mlx *mlx)
{
	pixel->x_com = mlx->julia_x;
	pixel->y_com = mlx->julia_y;
	z->x_com = x_to_complex_plan(*pixel, -2.00, 2.00);
	z->y_com = y_to_complex_plan(*pixel, -2.00, 2.00);
}

void	init_mandelbrot_set(t_point *z, t_point *pixel, t_mlx *mlx)
{
	(void)mlx;
	pixel->x_com = x_to_complex_plan(*pixel, -2.00, 2.00);
	pixel->y_com = y_to_complex_plan(*pixel, -2.00, 2.00);
	z->x_com = 0;
	z->y_com = 0;
}

void	fractol(t_mlx *mlx, t_point pixel, void (*f)(t_point *, t_point *,
			t_mlx *mlx))
{
	t_point	z;
	t_point	temp;
	int		iteration;

	f(&z, &pixel, mlx);
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
			fractol(mlx, data, mlx->set_func);
			data.x++;
		}
		data.y++;
	}
	clear_2d_tab(data.iteration_count);
}
