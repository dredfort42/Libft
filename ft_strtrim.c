/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:38:35 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/21 12:38:38 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		strlen;
	char	*tmp;
	char	*new_str;

	tmp = (char *)s1;
	if (!tmp || !set)
		return (0);
	while (*tmp && ft_strchr(set, *tmp))
		tmp++;
	strlen = ft_strlen(tmp);
	while (strlen && ft_strchr(set, tmp[strlen]))
		strlen--;
	new_str = ft_substr((char *) tmp, 0, strlen + 1);
	return (new_str);
}
