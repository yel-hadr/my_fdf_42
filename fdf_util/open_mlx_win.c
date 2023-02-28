/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_mlx_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:16:23 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 20:25:12 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	exit_game(t_myfdf *data)
{
	(void)data;
	exit (0);
}

int	handle_keypress(int keycode, t_myfdf *fdf)
{
	(void) fdf;
	mlx_destroy_image(fdf->mlx.mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx.mlx, fdf->win_len->len_win.x, \
			fdf->win_len->len_win.y);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
			&fdf->img.line_length, &fdf->img.endian);
	if (!event(keycode, fdf))
		return (0);
	else if (event(keycode, fdf) == 2)
		exit_game(fdf);
	ft_hook(*fdf);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_open_the_map(t_myfdf fdf, char *path)
{
	fdf.mlx.mlx = mlx_init();
	fdf.mlx.win = mlx_new_window(fdf.mlx.mlx, fdf.win_len->len_win.x, \
			fdf.win_len->len_win.y, "My_fdf");
	fdf.img.img = mlx_new_image(fdf.mlx.mlx, fdf.win_len->len_win.x, \
			fdf.win_len->len_win.y);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, \
			&fdf.img.line_length, &fdf.img.endian);
	baffer_the_map (path, fdf);
	mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.win, fdf.img.img, 0, 0);
	mlx_hook(fdf.mlx.win, 2, 0, handle_keypress, &fdf);
	mlx_hook(fdf.mlx.win, 17, 0, exit_game, &fdf);
	mlx_loop(fdf.mlx.mlx);
}
