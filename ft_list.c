/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:14:44 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 19:08:17 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_lst	*ft_pf_lstlast(t_pf_lst *lst)
{
	if (!(lst))
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int			ft_pf_lstadd_back(t_pf_lst **alst, t_pf_lst *new)
{
	t_pf_lst *tmp;

	if (!new)
		return (0);
	if (!(tmp = ft_pf_lstlast(*alst)))
		*alst = new;
	else
		tmp->next = new;
	return (1);
}

t_pf_lst	*ft_pf_lstnew(void *content, size_t size)
{
	t_pf_lst *node;

	if (!(node = (t_pf_lst *)malloc(sizeof(t_pf_lst))))
		return (NULL);
	node->size = size;
	node->next = NULL;
	node->content = content;
	return (node);
}

void		ft_pf_lstdelone(t_pf_lst *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void		ft_pf_lstclear(t_pf_lst **lst, void (*del)(void *))
{
	t_pf_lst *tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_pf_lstdelone(*lst, del);
		*lst = tmp;
	}
}
