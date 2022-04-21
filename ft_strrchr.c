/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:34:34 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/21 16:34:36 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	int		len;
	int		i;

	ps = (char *)s;
	len = ft_strlen(ps);
	i = 1;
	while (len - i >= 0)
	{
		if (ps[len - i] == c)
			return (&ps[len - i]);
		i++;
	}
	if (c == '\0')
		return (&ps[len]);
	return (0);
}
