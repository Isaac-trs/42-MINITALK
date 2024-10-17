/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:56:42 by istripol          #+#    #+#             */
/*   Updated: 2024/01/18 23:40:26 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			cpt;
	unsigned char	*copy;

	if (!dest && !src)
		return (NULL);
	copy = (unsigned char *)dest;
	cpt = 0;
	while (cpt < n)
	{
		copy[cpt] = cpt[(unsigned char *)src];
		cpt++;
	}
	return (dest);
}
