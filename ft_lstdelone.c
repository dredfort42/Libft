#include "libft.h"

/**
 * @brief Deletes a single node from the linked list.
 * @param lst Pointer to the node to be deleted.
 * @param del Function pointer to the function used to free the content of the node.
 */
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return;
	if (del)
		del(lst->content);
	free(lst);
}
