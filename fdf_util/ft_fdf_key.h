/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_key.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:35:49 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 21:18:23 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_KEY_H

# define FT_FDF_KEY_H

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define PLUS 69
# define MINUS 78
# define ANGEL_M 83
# define ANGEL_P 86
# define DEPTH_DW 84
# define DEPTH_UP 87

typedef struct s_set_bunus{
	int		angel;
	int		depth;
}				t_set_bunus;

typedef struct s_mlx{
	void	*mlx;
	void	*win;
}				t_mlx;

#endif