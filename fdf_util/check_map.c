/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:30:46 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/28 19:23:29 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	min_max_z(int *tab, int size, int *min, int *max)
{
	if (!tab)
		return ;
	while (size--)
	{
		if (*max <= tab[size])
			*max = tab[size];
		if (*min >= tab[size])
			*min = tab[size];
	}
	if (tab)
		free (tab);
}

void	ft_error(char *str, int i)
{
	if (str)
		ft_putstr_fd(str, 2);
	exit (i);
}

static int	ft_do_len(t_len_map *end, int map, int i)
{
	char	*str;

	str = get_next_line(map);
	if (!str)
		return (1);
	i = ft_count_word(str, ' ');
	if (!(end->x) || end->x == i)
		end->x = i;
	else
		ft_error("MAP_ERROR", 1);
	min_max_z(ft_line_split(str, ' '), end->x, &end->z_min, &end->z_max);
	end->y += 1;
	return (0);
}

t_len_map	*map_len(char *path)
{
	int			map;
	int			i;
	t_len_map	*end;

	if (!ft_strnstr(path, ".fdf", ft_strlen(path)))
		ft_error("INVALID MAP", 1);
	map = open(path, O_RDONLY);
	i = 0;
	if (map == -1)
		ft_error("MAP_ERROR", 1);
	end = ft_calloc(1, sizeof(t_len_map));
	if (!end)
		exit (1);
	*end = ft_do_t_len_map(0, 0, 0, 0);
	while (!i)
		i = ft_do_len(end, map, i);
	if (!(end->x) || !(end->y))
		ft_error("EMTY MAP", 1);
	close(map);
	return (end);
}
