/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:13:44 by istripol          #+#    #+#             */
/*   Updated: 2024/10/19 14:06:36by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_client_pid = 0;

int	receive_message(int signum)
{
	static unsigned int		bit_received;
	static unsigned char	c;
	static char				buf[2];
	static char				*str = NULL;

	if (str == NULL)
		str = ft_strdup("");
	c |= (signum == SIGUSR1);
	bit_received++;
	if (bit_received == 8)
	{
		if (c == 0)
		{
			ft_printf("From [%i]:\n	>> \"%s\"\n", g_client_pid, str);
			ft_printf("\n>>End of message<<\n");
			free(str);
			str = NULL;
			bit_received = 0;
			c = 0;
			kill(g_client_pid, SIGUSR2);
			return (1);
		}
		buf[0] = c;
		buf[1] = 0;
		str = ft_strjoin(str, buf);
		bit_received = 0;
		c = 0;
		//return (kill(g_client_pid, SIGUSR1));
	}
	else
		c <<= 1;
	return (kill(g_client_pid, SIGUSR1));
}

void	handler(int signum)
{
	static int				client_bit;
	static unsigned char	c;

	if (client_bit < 32)
	{
		g_client_pid <<= 1;
		g_client_pid |= (signum == SIGUSR1);
		client_bit++;
		if (client_bit == 32)
			ft_printf("client PID received |%u|\n", g_client_pid);
	}
	else if (client_bit == 32)
	{
		if (receive_message(signum))
		{
			client_bit = 0;
			g_client_pid = 0;
			ft_printf("Now waiting for messages...\n\n");
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
