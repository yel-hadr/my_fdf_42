/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:45:02 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 22:02:00 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./fdf_util/ft_fdf.h"

int	main(int ac, char **av)
{
	t_myfdf	*fdf;

	if (ac == 2)
	{
		fdf = ft_calloc(1, sizeof(t_myfdf));
		if (!fdf)
			return (1);
		if (ac != 2)
			return (1);
		fdf->end = map_len(av[1]);
		fdf->win_len = ft_len_of_win(*fdf->end);
		fdf->data = ft_calloc(fdf->end->y, sizeof(t_color_Z *));
		if (!fdf->data)
			return (1);
		ft_open_the_map(*fdf, av[1]);
		free(fdf->data);
		free(fdf->end);
		free(fdf->win_len);
		free(fdf);
	}
	return (0);
}
