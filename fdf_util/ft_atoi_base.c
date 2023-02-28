/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:59:41 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/24 16:54:59 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_fdf.h"

int	ft_atoi_base(const char *str)
{
	int	r;

	r = 0;
	str = ft_strnstr(str, "0x", ft_strlen(str));
	if (!str)
		return (0xFFFFFF);
	str += 2;
	while (*str && (ft_strchr(C, *str) || ft_strchr(A, *str)))
	{
		if (ft_strchr(C, *str))
			r = (r * 16) + (ft_strchr(C, *str) - C);
		else if (ft_strchr(A, *str))
			r = (r * 16) + (ft_strchr(A, *str) - A);
		str++;
	}
	return (r);
}
