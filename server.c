/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:13:44 by istripol          #+#    #+#             */
/*   Updated: 2024/12/27 17:15:54 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_client_pid = 0;

int	receive_message(int signum, int size)
{
	static unsigned int		bit_received;
	static unsigned char	c;
	static char				*str = NULL;
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
	static	int					client_bit;
	static	int					size_bit;
	static	unsigned int					size;

	if (client_bit < 32)
	{
		g_client_pid <<= 1;
		g_client_pid |= (signum == SIGUSR1);
		client_bit++;
		if (client_bit == 32)
			ft_printf("client PID received |%i|\n", g_client_pid);
	}
	else if (client_bit == 32 && size_bit < 32)
	{
		size <<= 1;
		size |= (signum == SIGUSR1);
		size_bit++;
		if (size_bit == 32)
			ft_printf("Size received |%i|\n", size);
		kill(g_client_pid, SIGUSR1);
	}
	else if (client_bit == 32 && size_bit == 32)
	{
		if (receive_message(signum, size))
		{
			client_bit = 0;
			g_client_pid = 0;
			size_bit = 0;
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