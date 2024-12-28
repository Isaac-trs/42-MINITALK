/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:01:45 by istripol          #+#    #+#             */
/*   Updated: 2024/12/26 06:19:11 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_ack;

void	send_client_pid(pid_t pid)
{
	pid_t	client_pid;
	int		bit_index;

	client_pid = getpid();
	bit_index = 31;
	ft_printf("client PID %d\n", client_pid);
	while (bit_index >= 0)
	{
		if ((1 << bit_index) & client_pid)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		usleep(1000);
	}
}

void	send_size(pid_t pid, unsigned int size)
{
	int	bit_index;

	bit_index = 31;
	while (bit_index >= 0)	
	{
		g_ack = 0;
		if ((1 << bit_index) & size)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		while (!g_ack)
			pause();
	}
}

void	send_message(pid_t pid, unsigned char *str)
{
	int	bit_index;

	while (*str || *str == 0)
	{
		bit_index = 7;
		while (bit_index >= 0)
		{
			g_ack = 0;
			if ((1 << bit_index) & *str)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_ack)
				pause();
			bit_index--;
		}
		if (*str)
			str++;
	}
}

//void	send_message(pid_t pid, unsigned char *str)
//{
//	while (*str)
//	{
//		send_char(pid, *str);
//		str++;
//	}
//	send_char(pid, '\0');
//}

void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		g_ack = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("\n>>MESSAGE SUCCESFULLY SENT<<\n");
		exit(0);
	}
	else
	{
		ft_printf("\n>>ACK ERROR<<\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int				serv_pid;

	if (ac != 3)
		return (ft_printf("Wrong number of args !\n"));
	serv_pid = atoi(1[av]);
	if (!serv_pid || kill(serv_pid, 0) == -1)
		return (ft_printf("Wrong PID!\n"));
	send_client_pid(serv_pid);
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	send_size(serv_pid, ft_strlen(2[av]));
	send_message(serv_pid, (unsigned char *)2[av]);
	return (0);
}
