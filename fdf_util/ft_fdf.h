/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:24:44 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 21:18:43 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H

# define FT_FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "ft_fdf_key.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct t_len_map{
	int	x;
	int	y;
	int	z_max;
	int	z_min;
}				t_len_map;

typedef struct s_point{
	int	x;
	int	y;
	int	color;
}				t_point;

typedef struct s_line{
	t_len_map	delta;
	t_len_map	index;
	int			error;
	int			step;
	int			e2;
}				t_line;

typedef struct s_color_Z{
	int	z;
	int	color;
}				t_color_Z;

typedef struct s_Matrix{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_Matrix;

typedef struct s_settings{
	t_len_map	len_win;
	int			zoom;
	int			start;
	int			start_x;
	int			angel_x;
	int			angel_y;
	int			depth;
}				t_settings;

typedef struct s_myfdf{
	t_settings	*win_len;
	t_len_map	*end;
	t_color_Z	**data;
	t_data		img;
	t_mlx		mlx;
}				t_myfdf;

t_len_map	*map_len(char *path);

void		min_max_z(int *tab, int size, int *min, int *max);
t_Matrix	ft_do_t_matrix(int x, int y, int z, int color);
int			abs_max(int a, int b);
t_point		ft_matrix_mult(t_Matrix matrix, t_settings len_win);
int			ft_gradient(int startcolor, int endcolor, int len, int pix);
t_len_map	ft_do_t_len_map(int x, int y, int z_max, int z_min);
int			*ft_line_split(char const *s, char c);

t_settings	*ft_len_of_win(t_len_map end);

void		ft_open_the_map(t_myfdf fdf, char *path);

t_color_Z	*ft_split_int(char const *s, t_myfdf fdf, int y);
void		baffer_the_map(char *path, t_myfdf fdf);

void		plot_line(t_point start, t_point end, t_myfdf fdf);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_open_the_map(t_myfdf fdf, char *path);
int			ft_atoi_base(const char *str);

void		ft_hook(t_myfdf fdf);

int			event(int keycode, t_myfdf *fdf);

#endif