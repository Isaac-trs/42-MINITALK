/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:35:25 by istripol          #+#    #+#             */
/*   Updated: 2024/01/18 23:10:35 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	cpt;

	cpt = 0;
	while (src[cpt])
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	dst[cpt] = 0;
	return (dst);
}
