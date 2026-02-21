/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:22:30 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 17:40:29 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	palette_dark_blue(double hue)
{
	int	r;
	int	g;
	int	b;

	if (hue < 0.0)
		hue = 0.0;
	if (hue > 1.0)
		hue = 1.0;
	r = 0;
	g = (int)(50 * hue);
	b = (int)(200 * hue);
	return (r << 16 | g << 8 | b);
}

int	palette_blue_red(double hue)
{
	int	r;
	int	b;
	int	g;

	if (hue < 0.0)
		hue = 0.0;
	if (hue > 1.0)
		hue = 1.0;
	r = (int)(255 * hue);
	g = 0;
	b = (int)(255 * (1.0 - hue));
	return (r << 16 | g << 8 | b);
}

int	palette_grey(double hue)
{
	int	c;

	c = (int)(255.0 * hue);
	return ((c << 16) | (c << 8) | c);
}

void	build_histogram(int **iteration_count, t_mlx *mlx)
{
	t_point	point;
	int		total_iteration;
	int		i;
	int		histogram[MAX_ITERATION];

	ft_memset(histogram, 0, sizeof(int) * MAX_ITERATION);
	point.x = 0;
	i = 0;
	while (point.x < WIDTH)
	{
		point.y = 0;
		while (point.y < HEIGHT)
		{
			i = iteration_count[point.x][point.y];
			histogram[i]++;
			point.y++;
		}
		point.x++;
	}
	total_iteration = get_total_iteration(histogram);
	get_color(total_iteration, iteration_count, histogram, mlx);
}

void	get_color(int total_iteration, int **iteration_count,
		int histogram[MAX_ITERATION], t_mlx *mlx)
{
	double	hue;
	int		iteration;
	int		i;
	int		color;
	t_point	point;

	point.x = 0;
	while (point.x < WIDTH)
	{
		point.y = 0;
		while (point.y < HEIGHT)
		{
			iteration = iteration_count[point.x][point.y];
			i = 0;
			hue = 0.0;
			while (++i < iteration)
			{
				hue += histogram[i] / (double)total_iteration;
			}
			color = palette_grey(hue);
			put_pixel(mlx->img_ptr, point.x, point.y, color);
			point.y++;
		}
		point.x++;
	}
}
