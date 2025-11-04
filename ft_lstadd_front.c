#include "libft.h"

/**
 * @brief Adds a new node at the beginning of the list.
 * @param lst Double pointer to the head of the list.
 * @param new Pointer to the new node to be added.
 */
void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
}
