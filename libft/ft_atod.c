/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:28:17 by llugez            #+#    #+#             */
/*   Updated: 2026/02/21 19:29:35 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft.h"
#include <math.h>

static double	divide_n_times(char *str)
{
	int		len;
	int		n;
	double	res;

	res = 0;
	len = ft_strlen(str);
	n = atoi(str);
	res = (double)n;
	while (len--)
	{
		res = res / 10;
	}
	return (res);
}

void	free_2d_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

double	check_entry(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!*str)
		return (NAN);
	while (str[i])
	{
		if (str[i] == '.' && !ft_isdigit(str[i + 1]))
			return (NAN);
		if (str[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count != 1)
		return (NAN);
	return (1.0);
}

double	ft_atod(char *str)
{
	char	**splitted;
	double	res;
	double	dec_part;
	int		i;
	int		ent_part;

	i = 0;
	if (isnan(check_entry(str)))
		return (NAN);
	splitted = ft_split(str, '.');
	ent_part = ft_atoi(splitted[0]);
	dec_part = divide_n_times(splitted[1]);
	if (ent_part < 0)
		res = ent_part - dec_part;
	else
		res = ent_part + dec_part;
	free_2d_tab(splitted);
	if (*str == '-')
		return (res * -1);
	return (res);
}
