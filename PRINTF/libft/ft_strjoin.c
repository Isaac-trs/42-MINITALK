/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 05:16:02 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:35:22 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);

	str = malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + len_s1, s2);
	return (str);
}
