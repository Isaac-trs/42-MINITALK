/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:34:56 by istripol          #+#    #+#             */
/*   Updated: 2024/01/16 23:20:06 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	sz_res = nmemb * size;
	void			*res;

	if (nmemb && sz_res / nmemb != size)
		return (0);
	res = malloc(sz_res);
	if (res)
		ft_bzero(res, sz_res);
	return (res);
}
