/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:13:14 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:13:16 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&head, (*d));
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
