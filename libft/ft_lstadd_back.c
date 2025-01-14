/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:57:25 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/08 18:59:32 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			i = ft_lstlast(*lst);
			i->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}

/*int	main()
{
	t_list	*node1 = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");
	t_list	*node3 = ft_lstnew("node3");
	t_list	*p = node1;

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node2, node3);
	//node3->next = NULL;
	while (p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
	return 0;
}*/