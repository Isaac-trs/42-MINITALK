/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 04:18:59 by istripol          #+#    #+#             */
/*   Updated: 2023/12/13 06:55:50 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*hs1;
	unsigned char	*hs2;
	size_t			i;

	hs1 = (unsigned char *)s1;
	hs2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (hs1[i] != hs2[i])
			return (hs1[i] - hs2[i]);
		i++;
	}
	return (0);
}
