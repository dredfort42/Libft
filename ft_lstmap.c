#include "libft.h"

/**
 * @brief Creates a new linked list by applying a function to each element of an existing list.
 * @param lst Pointer to the head of the original list.
 * @param f Function pointer to the function to be applied to each node's content.
 * @param del Function pointer to the function used to free the content of a node in case of failure.
 * @return Pointer to the head of the new list, or NULL if allocation fails.
 */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *node;
	void *content;

	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			if (del && content)
				del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
