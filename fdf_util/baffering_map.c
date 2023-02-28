/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baffering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:17:58 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/27 19:54:56 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	do_next(t_color_Z *line, t_Matrix point, t_myfdf fdf)
{
	t_Matrix	next;

	if (point.x > 0)
	{
		next = ft_do_t_matrix(point.x - 1, point.y, \
				line[point.x - 1].z, line[point.x - 1].color);
		plot_line(ft_matrix_mult(next, *fdf.win_len), \
				ft_matrix_mult(point, *fdf.win_len), fdf);
	}
	if (point.y > 0 && point.y < fdf.end->y)
	{
		next = ft_do_t_matrix(point.x, point.y - 1, \
				fdf.data[point.y - 1][point.x].z, \
				fdf.data[point.y - 1][point.x].color);
		plot_line(ft_matrix_mult(next, *fdf.win_len), \
				ft_matrix_mult(point, *fdf.win_len), fdf);
	}
}

static void	split(t_color_Z *r, char const *s, t_Matrix point, t_myfdf fdf)
{
	char		**data;

	data = ft_split(s, ' ');
	point.x = 0;
	while (point.x < fdf.end->x)
	{
		r[point.x].z = ft_atoi(data[point.x]);
		r[point.x].color = ft_atoi_base(data[point.x]);
		point = ft_do_t_matrix(point.x, point.y, \
				r[point.x].z, r[point.x].color);
		if (point.x > 0)
		{
			do_next(r, point, fdf);
		}
		if (point.y > 0 && point.y < fdf.end->y)
		{
			do_next(r, point, fdf);
		}
		point.x++;
	}
}

t_color_Z	*ft_split_int(char const *s, t_myfdf fdf, int y)
{
	t_color_Z	*result;
	t_Matrix	point;

	if (!s)
		return (NULL);
	result = ft_calloc(sizeof(t_color_Z *), ft_count_word(s, ' '));
	point.y = y;
	if (!result)
		return (NULL);
	split(result, s, point, fdf);
	return (result);
}

void	baffer_the_map(char *path, t_myfdf fdf)
{
	int	map;
	int	i;

	i = 0;
	map = open(path, O_RDONLY);
	while (i < fdf.end->y)
	{
		fdf.data[i] = ft_split_int(get_next_line(map), fdf, i);
		if (!fdf.data[i])
			break ;
		i++;
	}
	mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.win, fdf.img.img, 0, 0);
	close(map);
}
