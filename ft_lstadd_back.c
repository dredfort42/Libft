#include "libft.h"

/**
 * @brief Adds a new node at the end of the list.
 * @param lst Double pointer to the head of the list.
 * @param new Pointer to the new node to be added.
 */
void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!lst || !new)
		return;
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
