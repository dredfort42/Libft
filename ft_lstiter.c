#include "libft.h"

/**
 * @brief Iterates through the list and applies the function f to the content of each node.
 * @param lst Pointer to the head of the list.
 * @param f Function pointer to the function to be applied to each node's content.
 */
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
