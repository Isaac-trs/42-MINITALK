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

void	handler(int signum)
{
	static int				bit_received;
	static	unsigned int		client_pid =0;
	static	int				client_bit;
	static unsigned char	c;
	static int j =0;
	
	if (client_bit < 32 && !bit_received)
	{
		j++;
		client_bit++;
		client_pid |= (signum == SIGUSR1);
		if (client_bit < 32)
			client_pid <<= 1;
		//ft_printf("%i) client PID received |%i|\n", j,  (int)client_pid);
		else if (client_bit == 32)
			ft_printf("%i) client PID received |%i|\n", j,  (int)client_pid);

	}
	else if (client_bit == 32)
	{
		j = 0;
		//First bit to be transmitted
		c |= (signum == SIGUSR1);
		bit_received++;
		if (bit_received == 8)
		{
			if (c == 0)
			{
				ft_printf("\n>>End of message<<\n");
				client_pid = 0;
				client_bit = 0;
			}
			else
				ft_printf("%c", c);
			bit_received = 0;
			c = 0;
		}
		else
			c <<= 1;
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
	printf("server PID is  %d\n", elpid);
	printf("Now waiting for messages...\n\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

