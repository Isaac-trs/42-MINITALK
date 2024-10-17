/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:18:11 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:19:45 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*buf;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		buf = ft_lstnew(f(tmp->content));
		if (buf)
			ft_lstadd_back(&new, buf);
		else
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new);
}
