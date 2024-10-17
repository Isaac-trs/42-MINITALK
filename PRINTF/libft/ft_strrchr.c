/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:49:47 by istripol          #+#    #+#             */
/*   Updated: 2023/12/13 07:22:03 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			temp = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		temp = (char *)s + i;
	return (temp);
}
