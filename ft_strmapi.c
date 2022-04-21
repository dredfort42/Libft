/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:52:05 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/20 12:52:07 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ps;
	int		i;

	if (!s || !f)
		return (0);
	ps = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ps)
		return (0);
	i = 0;
	while (s[i])
	{
		ps[i] = f(i, s[i]);
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
