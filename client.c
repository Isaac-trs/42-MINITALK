/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:01:45 by istripol          #+#    #+#             */
/*   Updated: 2024/10/19 13:16:14 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_serv_pid;


void	send_client_pid(pid_t pid)
{
	int	bit_index;
	int	j = 1;
	bit_index = 31;
	unsigned int client_pid = getpid();

	ft_printf("client PID %d\n", client_pid);
	
	while (bit_index >= 0)
	{
		if ((1 << bit_index) & client_pid)
		{
			kill(pid, SIGUSR1);
			ft_printf("%i) 1 SENT SIGUSR1\n", j);
			usleep(1000);
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("%i) 0 SENT SIGUSR2\n", j);
			usleep(1000);
		}
		j++;
		bit_index--;
	}
}

void	send_char(pid_t pid, unsigned char c)
{
	static int	j = 1;
	int			bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((1 << bit_index) & c)
		{
			kill(pid, SIGUSR1);
			usleep(8000);
			ft_printf("%i) signal sent SIGUSR1\n", j);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(8000);
			ft_printf("%i) signal sent SIGUSR2\n", j);
		}
		bit_index--;
		j++;
	}
}

void	send_message(pid_t pid, unsigned char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, *str);
}

int	main(int ac, char **av)
{
	unsigned char	tmp;

	tmp = 0;
	if (ac != 3)
		return (printf("Wrong number of args !\n"));
	g_serv_pid = atoi(av[1]);
	if (!g_serv_pid || kill(g_serv_pid, 0) == -1)
		return (ft_printf("Wrong PID!\n"));
	ft_printf("message to be sent: |%s|\n", av[2]);
	send_client_pid(g_serv_pid);
	send_message(g_serv_pid, (unsigned char *)av[2]);
	return (0);
}