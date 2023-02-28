/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:59:18 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/25 12:14:36 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_r(int color)
{
	return ((color) >> 16);
}

int	ft_g(int color)
{
	return (((color) >> 8) & 0xFF);
}

int	ft_b(int color)
{
	return ((color) & 0xFF);
}

int	ft_rgb(int r, int g, int b)
{
	return (((r) << 16) + ((g) << 8) + (b));
}

int	ft_gradient(int startcolor, int endcolor, int len, int pix)
{
	double		increment[3];
	int			new[3];
	int			newcolor;

	increment[0] = (double)((ft_r(endcolor)) - \
			(ft_r(startcolor))) / (double)len;
	increment[1] = (double)((ft_g(endcolor)) - \
			(ft_g(startcolor))) / (double)len;
	increment[2] = (double)((ft_b(endcolor)) - \
			(ft_b(startcolor))) / (double)len;
	new[0] = (ft_r(startcolor)) + (pix * increment[0]);
	new[1] = (ft_g(startcolor)) + (pix * increment[1]);
	new[2] = (ft_b(startcolor)) + (pix * increment[2]);
	newcolor = ft_rgb(new[0], new[1], new[2]);
	return (newcolor);
}
