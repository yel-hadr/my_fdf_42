/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:27:05 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/27 19:38:59 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_cmp(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

static t_line	para_line(t_point start, t_point end)
{
	t_line	line;

	line.delta.x = abs(end.x - start.x);
	line.delta.y = -abs(end.y - start.y);
	line.index.x = ft_cmp(start.x, end.x);
	line.index.y = ft_cmp(start.y, end.y);
	line.error = line.delta.x + line.delta.y;
	line.step = 0;
	return (line);
}

static int	do_decision(t_line *line, t_point end, t_point *start)
{
	if (line->e2 >= line->delta.y)
	{
		if (start->x == end.x)
			return (0);
		line->error = line->error + line->delta.y ;
		start->x = start->x + line->index.x;
	}
	if (line->e2 <= line->delta.x)
	{
		if (start->y == end.y)
			return (0);
		line->error = line->error + line->delta.x;
		start->y = start->y + line->index.y;
	}
	return (1);
}

void	plot_line(t_point start, t_point end, t_myfdf fdf)
{
	int		color;
	t_line	line;

	line = para_line(start, end);
	while (1)
	{
		color = ft_gradient(start.color, end.color, \
				abs_max(line.delta.x, -line.delta.y), line.step);
		line.e2 = 2 * line.error;
		line.step++;
		if (start.x < fdf.win_len->len_win.x && \
				start.y + fdf.win_len->start < fdf.win_len->len_win.y && \
				start.y + fdf.win_len->start > 0 && start.x > 0)
			my_mlx_pixel_put(&(fdf.img), start.x, start.y + \
					fdf.win_len->start, color);
		if (!do_decision(&line, end, &start))
			break ;
		if (start.x == end.x + 1 && start.y == end.y - 1)
			break ;
	}
}
