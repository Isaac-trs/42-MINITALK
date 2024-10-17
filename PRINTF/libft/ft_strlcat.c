/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:32:05 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:06:50 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	cpt;

	if ((!src || !dst) && size == 0)
		return (0);
	src_len = ft_strlen(dst);
	cpt = 0;
	if (size <= src_len)
		return (ft_strlen(src) + size);
	while (src[cpt] && (src_len + cpt) < (size - 1))
	{
		dst[src_len + cpt] = src[cpt];
		cpt++;
	}
	dst[src_len + cpt] = 0;
	return (ft_strlen(src) + src_len);
}
