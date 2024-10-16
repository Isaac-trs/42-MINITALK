/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:09:20 by istripol          #+#    #+#             */
/*   Updated: 2024/10/11 12:02:13by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	handler(int signum)
{
	static int	bit_index;
	static unsigned char c;

	//First bit to be transmitted
	c |= (signum == SIGUSR1);
	/*if (signum == SIGUSR1)
		write(1, "RECEIVED SIGUSR1\n", 17);
	if (signum == SIGUSR2)
		write(1, "RECEIVED SIGUSR2\n", 17);
	*/
	bit_index++;

	if (bit_index == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
		{
			ft_putchar(c);
		//	write(1, "\n", 1);
		}
		bit_index = 0;
		c = 0;
	}
	else
		c <<=1;
}

void	handler_sigusr1(int signum)
{
	write(1, "Received SIGUSR1\n", 18);
}

void	handler_sigusr2(int signum)
{
	write(1, "Received SIGUSR2\n", 18);
}



int main()
{
//	struct sigaction	sa_sigusr1;
//	struct sigaction	sa_sigusr2;
	struct sigaction	sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
		// sa_sigusr1.sa_handler = handler_sigusr1;
		// sigemptyset(&sa_sigusr1.sa_mask);
		// sa_sigusr1.sa_flags = 0;

		//	sa_sigusr2.sa_handler = handler_sigusr2;
		//	sigemptyset(&sa_sigusr2.sa_mask);
		//	sa_sigusr2.sa_flags = 0;

	int elPid = getpid();
	printf("server PID is  %d\n", elPid);
	printf("Now waiting for messages...\n\n");
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
        
    while (1)
	{
		pause();
    }
    return 0;
}

