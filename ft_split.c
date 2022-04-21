/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:40:07 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/20 14:40:09 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_of_lines(char const *s, char c)
{
	int	i;
	int	strnum;

	if (!s[0])
		return (0);
	i = 0;
	strnum = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			strnum++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	strnum++;
	if (s[i - 1] == c)
		strnum--;
	return (strnum);
}

static void	ft_get_next(char **next, int *next_len, char c)
{
	int	i;

	*next += *next_len;
	*next_len = 0;
	i = 0;
	while (**next && **next == c)
		(*next)++;
	while ((*next)[i])
	{
		if ((*next)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

static void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}

static void	ft_do_split(char const *s, char c, char **arr)
{
	char	*next;
	int		next_len;
	int		i;

	i = 0;
	next = (char *)s;
	next_len = 0;
	while (i < ft_nbr_of_lines(s, c))
	{
		ft_get_next(&next, &next_len, c);
		arr[i] = malloc(sizeof(char) * (next_len + 1));
		if (!arr[i])
		{
			ft_free_split(arr);
		}
		ft_strlcpy(arr[i++], next, next_len + 1);
	}
	arr[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = malloc(sizeof(char *) * (ft_nbr_of_lines(s, c) + 1));
	if (!arr)
		return (0);
	ft_do_split(s, c, arr);
	return (arr);
}
