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

void	send_char(pid_t pid, unsigned char c)
{
	int	bit_index;
	static int j = 1;
	
	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((1 << bit_index) & c)
		//if ((c >> bit_index ) & 1)
		{
			kill(pid, SIGUSR1);
			usleep(500);
			printf("%i) signal sent SIGUSR1\n", j);
		}	
		else
		{	
			kill(pid, SIGUSR2);
			usleep(500); // Use it depending size of the string, >100 char no need
			printf("%i) signal sent SIGUSR2\n", j);
		}
		bit_index--;
		j++;
	}
}

void	send_message(pid_t pid, unsigned char *str)
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



if (ac != 3)
		return(printf("Wrong number of args !\n"));
	serv_pid = atoi(av[1]);
	if (!serv_pid || kill(serv_pid, 0) == -1)
		return(printf("Wrong PID!\n"));
	//send_message(serv_pid, av[2]);
	int i = 0;
	int j = 1;

	printf("message: |%s|\n", av[2]);
	send_message(serv_pid, av[2]);
	return (0);
}
