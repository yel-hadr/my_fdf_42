/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evant_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:09:37 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 21:58:51 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_fdf.h"

int	event(int keycode, t_myfdf *fdf)
{
	if (keycode == DEPTH_UP)
		fdf->win_len->depth++;
	else if (keycode == DEPTH_DW)
		fdf->win_len->depth--;
	else if (keycode == ESC)
		return (2);
	else
		return (0);
	return (1);
}
