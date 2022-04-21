/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dredfort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:36:32 by dredfort          #+#    #+#             */
/*   Updated: 2021/04/21 15:36:34 by dredfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*last;
	t_list	*item;
	void	*content;

	nlst = 0;
	last = 0;
	while (lst)
	{
		content = f(lst->content);
		item = ft_lstnew(content);
		if (!item)
		{
			if (nlst)
				ft_lstclear(&nlst, del);
			return (0);
		}
		if (last)
			last->next = item;
		if (!nlst)
			nlst = item;
		last = item;
		lst = lst->next;
	}
	return (nlst);
}
