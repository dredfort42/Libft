/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:36:14 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/21 16:36:27 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*phaystack;
	size_t	charnum;
	size_t	i;
	size_t	ndllen;

	phaystack = (char *)haystack;
	ndllen = ft_strlen(needle);
	if (ndllen == 0 || haystack == needle)
		return (phaystack);
	charnum = 0;
	while (phaystack[charnum] && charnum < len)
	{
		i = 0;
		while (phaystack[charnum + i] && needle[i]
			&& phaystack[charnum + i] == needle[i] && charnum + i < len)
			i++;
		if (i == ndllen)
			return (phaystack + charnum);
		charnum++;
	}
	return (0);
}
