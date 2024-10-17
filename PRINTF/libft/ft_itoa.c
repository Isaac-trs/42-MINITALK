/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:49 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 15:22:35 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	static int	counter;

	counter = 0;
	if (n > 9)
		count_digits(n / 10);
	counter++;
	return (counter);
}

char	*ft_itoa(int n)
{
	unsigned int	m;
	int				digits;
	char			*res;

	m = n;
	if (n < 0)
		m = -n;
	digits = count_digits(m) + (n < 0);
	res = malloc(digits + 1);
	if (!res)
		return (NULL);
	res[digits] = 0;
	if (n < 0)
		*res = '-';
	while (--digits >= 0 + (n < 0))
	{
		res[digits] = m % 10 + '0';
		m /= 10;
	}
	return (res);
}
