/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:18:48 by istripol          #+#    #+#             */
/*   Updated: 2023/12/13 06:10:50 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*dst;	

	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (!n)
		return (dest);
	if (dest > src)
	{
		while (n-- > 0)
			dst[n] = str[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
