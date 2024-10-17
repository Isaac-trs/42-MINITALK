/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:37:17 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:43:38 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*str;
	const size_t	len = ft_strlen(s);

	str = malloc(len + 1);
	if (str)
		ft_strlcpy(str, s, len + 1);
	return (str);
}
