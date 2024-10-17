/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:53:42 by istripol          #+#    #+#             */
/*   Updated: 2024/01/18 22:28:10 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*buf;

	tmp = *lst;
	while (tmp)
	{
		del(tmp->content);
		buf = tmp;
		tmp = tmp->next;
		free(buf);
	}
	*lst = (NULL);
}
