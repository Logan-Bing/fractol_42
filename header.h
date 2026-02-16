#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800 
# define MALLOC_ERROR 1
# define ESC_CODE 65307
# define MAX_ITERATION 50

#define EXIT_CLEAN 0
#define EXIT_ERROR 1

typedef struct s_point {
  int    x;
  int    y;
  int    **iteration_count;
  double x_com; //x
  double y_com;    //y
} t_point;

typedef struct s_img{
	void	*img; // pointeur MLX vers l'image
	char	*img_pixel; // adresse memoir du pixel
	int		bpp; // bits par pixel
	int		line_length; // nombre octets par ligne 1920 * 4 = 7680
	int		endian; // ordre des octets
}				t_img;

typedef struct s_mlx_constructor{
  void  *connection;
  void  *window;
  t_img *img_ptr;
}              t_mlx;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	DESTROY_NOTIFY = 17,
};


// COLOR.c
int	get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);
int	create_trgb(int t, int r, int g, int b);
int add_shade(double distance, int color);

// MAIN
void   put_pixel(t_img *img, int x, int y, int color);

// HOOK
int  keypress(int keycode, t_mlx *mlx);
int  mouse_hook(int button, int x, int y, t_mlx *mlx);
int close_window(t_mlx *mlx);
void  clean_mlx(t_mlx *mlx);

// UTILS
double y_to_complex_plan(int py, int height, double min_y, double max_y);
double x_to_complex_plan(int px, int width, double min_x, double max_x);
int get_total_iteration(int histogram[MAX_ITERATION]);

// COLOR ALGO
void  get_color(int total_iteration, int **iteration_count, int histogram[MAX_ITERATION], t_mlx *mlx);
void  build_histogram(int **iteration_count, t_mlx *mlx);

void fractol(t_mlx *mlx, t_point pixel);
void  for_each_pixel(t_mlx *mlx, void (*f)(t_mlx *, t_point point));
void print_2d_tab(int **tab);
#endif
