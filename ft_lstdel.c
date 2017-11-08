#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_elem;

	while (*alst != NULL)
	{
		next_elem = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next_elem;
	}
}