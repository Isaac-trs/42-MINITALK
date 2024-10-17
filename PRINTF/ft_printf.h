/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocket <rocket@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:16:14 by istripol          #+#    #+#             */
/*   Updated: 2024/05/02 06:06:41 by rocket           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

# ifndef HEX
#  define HEX "0123456789abcdef0123456789ABCDEF"
# endif

int		ft_printf(const char *string, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_base(unsigned long n, int base, unsigned int upper);

#endif
