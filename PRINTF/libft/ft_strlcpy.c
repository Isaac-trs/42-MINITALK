/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:44:18 by istripol          #+#    #+#             */
/*   Updated: 2024/01/18 23:18:51 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cpt;

	cpt = 0;
	if (size > cpt)
	{
		while (src[cpt] && cpt < size - 1)
		{
			dst[cpt] = src[cpt];
			cpt++;
		}
		dst[cpt] = '\0';
	}
	return (ft_strlen(src));
}
