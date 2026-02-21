/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:22:42 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 18:19:55 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MALLOC_ERROR 1
# define ESC_CODE 65307
# define MAX_ITERATION 50

# define EXIT_CLEAN 0
# define EXIT_ERROR 1

typedef struct s_point
{
	int		x;
	int		y;
	int		**iteration_count;
	double	x_com;
	double	y_com;
	double	zoom;
}			t_point;

typedef struct s_img
{
	void	*img;
	char	*img_pixel;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx_constructor
{
	void	*connection;
	void	*window;
	t_img	*img_ptr;
	void	*set_func;
	double	julia_x;
	double	julia_y;
}			t_mlx;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	DESTROY_NOTIFY = 17,
};

// MAIN
void		put_pixel(t_img *img, int x, int y, int color);

// MLX_CONFIG
void		init_deps(t_mlx *mlx);
void		*init_mlx_connection(t_mlx *mlx);
void		*init_mlx_image(t_mlx *mlx);

// HOOK
int			keypress(int keycode, t_mlx *mlx);
int			mouse_hook(int button, int x, int y, t_mlx *mlx);
int			close_window(t_mlx *mlx);
void		clean_mlx(t_mlx *mlx);
void		render(t_mlx *mlx, double scale);

// UTILS
double		y_to_complex_plan(t_point pixel, double min_y, double max_y);
double		x_to_complex_plan(t_point pixel, double min_x, double max_x);
int			get_total_iteration(int histogram[MAX_ITERATION]);
void		clear_2d_tab(int **tab);

// COLOR ALGO
void		get_color(int total_iteration, int **iteration_count,
				int histogram[MAX_ITERATION], t_mlx *mlx);
void		build_histogram(int **iteration_count, t_mlx *mlx);

void		fractol(t_mlx *mlx, t_point pixel, void (*f)(t_point *, t_point *,
					t_mlx *));
void		for_each_pixel(t_mlx *mlx, double scale);
void		init_julia_set(t_point *z, t_point *pixel, t_mlx *mlx);
void		init_mandelbrot_set(t_point *z, t_point *pixel, t_mlx *mlx);
int			**init_iteration_count(void);

#endif
