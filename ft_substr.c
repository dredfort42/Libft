/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:31:38 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/21 16:31:40 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*substr(char *sub, const char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (0);
	if (ft_strlen(s) < start || !len)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start > len)
		size = len;
	else
		size = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (size + 1));
	if (!sub)
		return (0);
	substr(sub, s, start, len);
	if (!sub)
		return (0);
	return (sub);
}
