/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:23:10 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 17:53:40 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*init_mlx_connection(t_mlx *mlx)
{
	mlx->connection = mlx_init();
	if (!mlx->connection)
		return (NULL);
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, "Fractol");
	if (!mlx->window)
		return (NULL);
	return (mlx);
}

void	*init_mlx_image(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	mlx->img_ptr = img;
	img->img = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	img->img_pixel = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	return (img);
}

void	init_deps(t_mlx *mlx)
{
	if (!init_mlx_connection(mlx))
		exit(MALLOC_ERROR);
	init_mlx_image(mlx);
}
