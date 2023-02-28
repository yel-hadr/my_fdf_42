/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:22:29 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/02/24 22:23:44 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static size_t	start_char(const char *str, char c, size_t b)
{
	while (str[b] && (str[b] == c || str[b] == '\n'))
		b++;
	return (b);
}

static size_t	end_char(const char *str, char c, size_t i)
{
	while (str[i] && str[i] != c && str[i] != '\n')
		i++;
	return (i);
}

static void	split_line(int *r, char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	b;

	i = 0;
	count = 0;
	while (s[i])
	{
		i = start_char(s, c, i);
		b = end_char(s, c, i);
		if (i < b)
			r[count++] = ft_atoi(s + i);
		i = b;
	}
}

int	*ft_line_split(char const *s, char c)
{
	int	*result;

	if (!s)
		return (NULL);
	result = ft_calloc(sizeof(int), ft_count_word(s, c) + 1);
	if (!result)
		return (NULL);
	split_line(result, s, c);
	return (result);
}
