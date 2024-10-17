/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:38:30 by istripol          #+#    #+#             */
/*   Updated: 2024/04/26 18:27:43 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	return (ft_putstr_fd("0x", 1) + ft_print_base(ptr, 16, 0));
}
