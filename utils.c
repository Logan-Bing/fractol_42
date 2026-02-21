/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:24:27 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 17:26:30 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_total_iteration(int histogram[MAX_ITERATION])
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < MAX_ITERATION)
	{
		total += histogram[i];
		i++;
	}
	return (total);
}

double	x_to_complex_plan(t_point pixel, double min_x, double max_x)
{
	return ((min_x + ((double)pixel.x / (WIDTH - 1)) * (max_x - min_x))
		/ pixel.zoom);
}

double	y_to_complex_plan(t_point pixel, double min_y, double max_y)
{
	return ((max_y - ((double)pixel.y / (HEIGHT - 1)) * ((max_y - min_y)))
		/ pixel.zoom);
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
