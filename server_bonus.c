/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:47:36 by mmonika           #+#    #+#             */
/*   Updated: 2024/12/01 15:15:06 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	sig_handler(int mysignal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	(void)context;
	c = (c << 1) | (mysignal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		else
			ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("\033[1;32mHi! welcome to my terminal 😊\033[0m\n");
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}

//server client k signal pathabe;