/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:55:26 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:38:59 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = malloc(n + 1);
	if (str)
		ft_strlcpy(str, s, n + 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	while (s1[i])
		i++;
	while (--i >= start && ft_strchr(set, s1[i]))
		;
	return (ft_strndup(s1 + start, i - start + 1));
}
