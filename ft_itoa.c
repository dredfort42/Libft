/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:34:41 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/20 13:34:43 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isminus(int *n)
{
	int	minus;

	minus = 0;
	if (*n < 0)
	{
		*n *= -1;
		minus = 1;
	}
	return (minus);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		minus;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 0;
	minus = ft_isminus(&n);
	len = ft_numlen(n) + minus + 2;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (minus)
		str[0] = '-';
	return (str);
}
