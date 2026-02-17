#include "header.h"

t_mlx	*init_mlx_connection(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->connection = mlx_init();
	if (!mlx->connection)
		return (NULL);
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, "Fractol");
	if (!mlx->window)
		return (NULL);
	return (mlx);
}

// TODO: Need to return an errror if malloc failded
void	init_mlx_image(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return ;
	mlx->img_ptr = img;
	img->img = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	img->img_pixel = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
}

t_mlx	*init_deps(void)
{
	t_mlx	*mlx;

	mlx = init_mlx_connection();
	if (!mlx)
		exit(EXIT_ERROR);
	init_mlx_image(mlx);
	return (mlx);
}
