#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8| b);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_g(int trgb)
{
	return (trgb >> 8 & 0xFF);
}

int get_r(int trgb)
{
	return (trgb >> 16 & 0xFF);
}

int	get_t(int trgb)
{
	return (trgb >> 24 & 0xFF);
}

int add_shade(double distance, int color)
{
	int t = get_t(color);
	int r = get_r(color);
	int g = get_g(color);
	int b = get_b(color);

	r = r * (1.0 - distance);
	g = g * (1.0 - distance);
	b = b * (1.0 - distance);

	return (create_trgb(t, r, g, b));
}
