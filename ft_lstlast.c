#include "libft.h"

/**
 * @brief Returns the last node of the linked list.
 * @param lst Pointer to the head of the list.
 * @return Pointer to the last node of the list, or NULL if the list is empty.
 */
t_list *ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
