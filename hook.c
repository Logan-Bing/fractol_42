/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:22:44 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 17:23:35 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_CODE)
	{
		clean_mlx(mlx);
		exit(EXIT_CLEAN);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	clean_mlx(mlx);
	exit(EXIT_CLEAN);
}

void	render(t_mlx *mlx, double scale)
{
	for_each_pixel(mlx, scale);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img_ptr->img, 0,
		0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	static double	scale;

	if (button == 4)
	{
		scale += 0.5;
		render(mlx, scale);
	}
	if (button == 5 && scale)
	{
		scale -= 0.5;
		render(mlx, scale);
	}
	(void)x;
	(void)y;
	return (1);
}

void	clean_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_image(mlx->connection, mlx->img_ptr->img);
	mlx_destroy_display(mlx->connection);
	if (mlx->img_ptr)
		free(mlx->img_ptr);
	if (mlx->connection)
		free(mlx->connection);
	if (mlx)
		free(mlx);
}
