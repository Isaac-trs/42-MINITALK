/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocket <rocket@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:34:22 by istripol          #+#    #+#             */
/*   Updated: 2024/05/02 06:16:33 by rocket           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	flags_processor(const char id, va_list ap)
{
	int	tmp;

	if (id == '%')
		return (ft_print_char(id));
	else if (id == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (id == 's')
		return (ft_print_string(va_arg(ap, char *)));
	else if (id == 'u')
		return (ft_print_base(va_arg(ap, unsigned int), 10, 0));
	else if (id == 'd' || id == 'i')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
		{
			ft_putchar_fd('-', 1);
			return (1 + ft_print_base((unsigned)tmp * -1, 10, 0));
		}
		return (ft_print_base((unsigned)tmp, 10, 0));
	}
	else if (id == 'x' || id == 'X')
		return (ft_print_base(va_arg(ap, unsigned int), 16, id == 'X'));
	else if (id == 'p')
		return (ft_print_ptr((unsigned long)va_arg(ap, void *)));
	return (ft_print_char('%'));
}

int	ft_printf(const char *string, ...)
{
	va_list		ap;
	int			cpt;

	if (!string)
		return (0);
	cpt = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
			cpt += flags_processor(*++string, ap);
		else
			cpt += ft_print_char(*string);
		string++;
	}
	va_end(ap);
	return (cpt);
}
