/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:34:55 by istripol          #+#    #+#             */
/*   Updated: 2024/10/11 07:48:19by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		serv_pid;

void	send_char(pid_t pid, char c)
{
	int	bit_index;
	
	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((1 << bit_index) & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		usleep(100);
	}
	
}

void	send_message(pid_t pid, char *str)
{
	while(*str)		
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, *str);
}

int	main(int ac, char **av)
{
	unsigned char tmp = 0;
	printf("a = 0\n");
	tmp = 1 << 7 | mtp; // 128 = 1000 000
				//  0   0000 000 	OR = 1000 0000	AND = 0000 0000 	XOR = 1000 0000
			1 << 6 | tmp; // 64	= 0100 0000 & 1000 0000		tmp = 0100 0000
			1 << 5 | tmp; // 32	= 0010 0000 & 0100 0000		tmp = 0010 0000
	if (ac != 3)
		return(printf("Wrong number of args !\n"));
	serv_pid = atoi(av[1]);
	if (!serv_pid || kill(serv_pid, 0) == -1)
		return(printf("Wrong PID!\n"));
	send_message(serv_pid, av[2]);
	return (0);
}