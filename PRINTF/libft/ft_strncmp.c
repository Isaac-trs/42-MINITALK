/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:12:43 by istripol          #+#    #+#             */
/*   Updated: 2024/01/18 23:46:20 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cpt;

	cpt = 0;
	while ((s1[cpt] || s2[cpt]) && cpt < n)
	{
		if ((unsigned char)s1[cpt] != (unsigned char)s2[cpt])
			return ((unsigned char)s1[cpt] - (unsigned char)s2[cpt]);
		cpt++;
	}
	return (0);
}
