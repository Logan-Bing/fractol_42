/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llugez <llugez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:49:48 by llugez            #+#    #+#             */
/*   Updated: 2025/11/11 13:19:34 by llugez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= '0'
			&& c <= '9'));
}

/*
int	main(void)
{
	unsigned char	sentence[255];
	int				i;
	int				my_res;
	int				real_res;

	i = 0;
	my_res = 0;
	real_res = 0;
	printf("=== LA MIENNE ===\n");
	while (i < 255)
	{
		sentence[i] = i;
		my_res = ft_isalnum(sentence[i]);
		real_res = isalnum(sentence[i]);
		if (my_res != real_res)
		{
			printf("[%d]", my_res);
			printf("[%d] === FALSE", real_res);
		} else
		{
			printf("[%d]", my_res);
			printf("[%d] === OK", real_res);
		}
		printf("\n");
		i++;
	}
}
*/