/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 03:56:32 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:41:04 by istripol         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	taille;
	size_t	size_str;

	if (!s)
		return (NULL);
	taille = ft_strlen(s);
	if (taille <= start)
		return (ft_strdup(""));
	size_str = taille - start;
	if (len <= size_str)
		size_str = len;
	else if (taille > len)
		size_str = len - size_str;
	return (ft_strndup(s + start, size_str));
}
