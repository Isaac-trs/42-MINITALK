/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:13:44 by istripol          #+#    #+#             */
/*   Updated: 2025/01/06 16:03:49 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_client_pid = 0;

void	receive_pid_and_size(int signum, void *i)
{
	static int	signum_received;

	if (signum_received < 32)
	{
		*(pid_t *)i <<= 1;
		*(pid_t *)i |= (signum == SIGUSR1);
		signum_received++;
		if (signum_received == 32)
			ft_printf("client PID received |%i|\n", *(pid_t *)i);
	}
	else if (signum_received >= 32 && signum_received < 64)
	{
		*(unsigned int *)i <<= 1;
		*(unsigned int *)i |= (signum == SIGUSR1);
		signum_received++;
		if (signum_received == 64)
		{
			ft_printf("string SIZE received |%u|\n", *(unsigned int *)i);
			signum_received = 0;
		}
		kill(g_client_pid, SIGUSR1);
	}
}

int	process_bits(int signum, unsigned char **str, int *i)
{
	static unsigned int		bit_received;
	static unsigned char	c;

	c |= (signum == SIGUSR1);
	bit_received++;
	if (bit_received == 8)
	{
		if (c == 0)
		{
			bit_received = 0;
			c = 0;
			return (1);
		}
		*(*str + *i) = c;
		(*i)++;
		bit_received = 0;
		c = 0;
	}
	else
		c <<= 1;
	return (0);
}

int	receive_message(int signum, unsigned int size)
{
	static unsigned char	*str = NULL;
	static int				i;

	if (str == NULL)
	{
		str = ft_calloc(size + 1, sizeof(unsigned char));
		if (!str)
		{
			ft_printf("\n>>CALLOC ERROR EXITING<<\n");
			exit(0);
		}
	}
	if (process_bits(signum, &str, &i))
	{
		ft_printf("From [%i]:\n    >> \"%s\"\n\n>>End of message<<\n",
			g_client_pid, str);
		free(str);
		str = NULL;
		i = 0;
		return (1);
	}
	return (0);
}

void	handler(int signum)
{
	static int						bits_received;
	static unsigned int				size;

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
		if (!receive_message(signum, size))
			kill(g_client_pid, SIGUSR1);
		else
		{
			bits_received = 0;
			size = 0;
			kill(g_client_pid, SIGUSR2);
			g_client_pid = 0;
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
	sa.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
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
