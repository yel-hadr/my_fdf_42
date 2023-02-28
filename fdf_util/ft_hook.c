/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:43:03 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 21:10:40 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	do_hook(t_Matrix	point, int x, int y, t_myfdf fdf)
{
	t_Matrix	next;

	if (x != fdf.end->x - 1)
	{
		next = ft_do_t_matrix(x + 1, y, fdf.data[y][x + 1].z, \
				fdf.data[y][x + 1].color);
		plot_line(ft_matrix_mult(next, *fdf.win_len), \
				ft_matrix_mult(point, *fdf.win_len), fdf);
	}
	if (y != fdf.end->y - 1)
	{
		next = ft_do_t_matrix(x, y + 1, fdf.data[y + 1][x].z, \
				fdf.data[y + 1][x].color);
		plot_line(ft_matrix_mult(next, *fdf.win_len), \
				ft_matrix_mult(point, *fdf.win_len), fdf);
	}
}

void	ft_hook(t_myfdf fdf)
{
	t_Matrix	point;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < fdf.end->y)
	{
		x = 0;
		while (x < fdf.end->x)
		{
			point = ft_do_t_matrix(x, y, fdf.data[y][x].z, \
					fdf.data[y][x].color);
			do_hook(point, x, y, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.win, fdf.img.img, 0, 0);
}
