/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:34:27 by istripol          #+#    #+#             */
/*   Updated: 2023/12/20 01:26:10 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*hld;
	unsigned int	i;

	hld = (unsigned char *)s;
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			hld[i] = '\0';
			i++;
		}
		s = hld;
	}
}
