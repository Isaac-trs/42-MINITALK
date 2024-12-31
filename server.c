/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:13:44 by istripol          #+#    #+#             */
/*   Updated: 2024/12/31 06:23:10 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_client_pid = 0;

void	receive_pid_and_size(int signum, int *i)
{
	static int	signum_received;
	
	if (signum_received < 32)
	{
		*i <<= 1;
		*i |= (signum == SIGUSR1);
		signum_received++;
		if (signum_received == 32)
			ft_printf("client PID received |%i|\n", *i);
	}
	else if (signum_received >= 32 && signum_received < 64)
	{
		*i <<= 1;
		*i |= (signum == SIGUSR1);
		signum_received++;
		if (signum_received == 64)
		{
			ft_printf("client SIZE received |%i|\n", *i);
			signum_received = 0;
		}
		kill(g_client_pid, SIGUSR1);
	}
}

int	receive_message(int signum, int size)
{
	static unsigned int		bit_received;
	static unsigned char	c;
	static unsigned char				*str = NULL;
	static int				i;

	if (str == NULL)
		str = ft_calloc(size + 1, sizeof(char));
	c |= (signum == SIGUSR1);
	bit_received++;
	if (bit_received == 8)
	{
		if (c == 0)
		{
			printf("From [%i]:\n	>> \"%s\"\n\n>>End of message<<\n", g_client_pid, str);
			free(str);
			str = NULL;
			bit_received = 0;
			c = 0;
			i = 0;
			kill(g_client_pid, SIGUSR2);
			return (1);
		}
		*(str+i) = c;
		i++;
		bit_received = 0;
		c = 0;
	}
	else
		c <<= 1;
	return (kill(g_client_pid, SIGUSR1));
}

void	handler(int signum)
{
	static	int					bits_received;
	static	int					size;

	if (bits_received < 64)
	{
		if (bits_received < 32)
			receive_pid_and_size(signum, &g_client_pid);
		else 
			receive_pid_and_size(signum, &size);
		bits_received++;
	}
	else if (bits_received == 64)
	{
		if (receive_message(signum, size))
		{
			bits_received = 0;
			g_client_pid = 0;
			size = 0;
			ft_printf("Now waiting for new messages...\n\n");
		}
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					elpid;

	elpid = getpid();
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	ft_printf("server PID is  %d\n", elpid);
	ft_printf("Now waiting for messages...\n\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}