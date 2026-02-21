/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:22:57 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 18:14:41 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_pixel + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	display_available_params(void)
{
	ft_printf("---PARAMS---\n");
	ft_printf("- mandelbrot\n");
	ft_printf("- julia -x -y\n");
	ft_printf("exemple of set for julia: x:0.3 y:0.5");
}

void	*parse_args(int argc, char *argv[], t_mlx *mlx)
{
	if (argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen("julia")))
	{
		mlx->julia_x = ft_atod(argv[2]);
		mlx->julia_y = ft_atod(argv[3]);
		if (isnan(mlx->julia_x) || isnan(mlx->julia_y))
		{
			free(mlx);
			display_available_params();
			exit(1);
		}
		return (&init_julia_set);
	}
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot",
			ft_strlen("mandelbrot")))
	{
		return (&init_mandelbrot_set);
	}
	display_available_params();
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	void	*chosen_func;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit(1);
	chosen_func = parse_args(argc, argv, mlx);
	if (!chosen_func)
	{
		free(mlx);
		exit(1);
	}
	init_deps(mlx);
	mlx->set_func = chosen_func;
	for_each_pixel(mlx, 0.0);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img_ptr->img, 0,
		0);
	mlx_hook(mlx->window, DESTROY_NOTIFY, 0, close_window, mlx);
	mlx_hook(mlx->window, 02, (1L << 0), keypress, mlx);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	mlx_loop(mlx->connection);
}
