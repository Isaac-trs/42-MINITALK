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

void	handler(int signum)
{
	static int	bits_received = 0;
	char c = 0;

	while (bits_received < 8)
	{
		if (signum == SIGUSR1)		
			c = c >> bits_received & 1;
	}
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
	struct sigaction	sa_sigusr1;
	struct sigaction	sa_sigusr2;

	sa_sigusr1.sa_handler = handler_sigusr1;
	sigemptyset(&sa_sigusr1.sa_mask);
	sa_sigusr1.sa_flags = 0;

	sa_sigusr2.sa_handler = handler_sigusr2;
	sigemptyset(&sa_sigusr2.sa_mask);
	sa_sigusr2.sa_flags = 0;

	int	elPid = getpid();    
    printf("server PID is  %d\n", elPid);
	printf("Now waiting for messages...\n\n");
	
	sigaction(SIGUSR1, &sa_sigusr1, NULL);
	sigaction(SIGUSR2, &sa_sigusr2, NULL);
        
    while (1)
	{
		pause();
    }
    return 0;
}

