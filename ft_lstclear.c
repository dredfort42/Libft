/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:19:32 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/21 15:19:39 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*p;

	if (lst && del)
	{
		p = *lst;
		while (p)
		{
			tmp = p->next;
			del(p->content);
			free(p);
			p = tmp;
		}
	}
	*lst = 0;
}
