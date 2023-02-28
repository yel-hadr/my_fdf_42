/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evant.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:55:42 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 22:00:41 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	do_evant(int keycode, t_myfdf *fdf)
{
	if (keycode == ANGEL_P)
	{
		fdf->win_len->angel_y += 5;
		fdf->win_len->angel_x += 5;
	}
	else if (keycode == ANGEL_M)
	{
		fdf->win_len->angel_y -= 5;
		fdf->win_len->angel_x -= 5;
	}
	else if (keycode == 91)
	{
		fdf->win_len->angel_y = -80;
		fdf->win_len->angel_x = -10;
	}
	else if (keycode == 89)
	{
		fdf->win_len->angel_y = -60;
		fdf->win_len->angel_x = -30;
	}
	return (0);
}

int	event(int keycode, t_myfdf *fdf)
{
	if (keycode == ANGEL_P || keycode == ANGEL_M \
			|| keycode == 91 || keycode == 89)
		do_evant(keycode, fdf);
	else if (keycode == UP)
		fdf->win_len->start -= 10;
	else if (keycode == DOWN)
		fdf->win_len->start += 10;
	else if (keycode == MINUS)
		fdf->win_len->zoom -= 1;
	else if (keycode == PLUS)
		fdf->win_len->zoom += 1;
	else if (keycode == RIGHT)
		fdf->win_len->start_x += 10;
	else if (keycode == LEFT)
		fdf->win_len->start_x -= 10;
	else if (keycode == DEPTH_UP)
		fdf->win_len->depth++;
	else if (keycode == DEPTH_DW)
		fdf->win_len->depth--;
	else if (keycode == ESC)
		return (2);
	else
		return (0);
	return (1);
}
