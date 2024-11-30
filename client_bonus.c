/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:43:09 by mmonika           #+#    #+#             */
/*   Updated: 2024/11/25 18:02:07 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

int	check_pid(pid_t server_pid)
{
	if (kill(server_pid, SIGUSR2) == -1)
	{
		ft_printf("wrong pid. type carefully...\n");
		exit (0);
	}
	return (1);
}

void	send_bit(pid_t server_pid, char c)
{
	int		bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

void	sigcon_handler(int mysignal)
{
	if (mysignal == SIGUSR1)
		ft_printf("Received bit 1\n");
	else if (mysignal == SIGUSR2)
		ft_printf("Received bit 0\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sca;
	int					server_pid;
	int					i;
	sca.sa_handler = sigcon_handler;
	sigemptyset(&sca.sa_mask);
	sca.sa_flags = 0;
	sigaction(SIGUSR1, &sca, NULL);
	sigaction(SIGUSR2, &sca, NULL);
	if (argc != 3)
		exit(0);
	server_pid = ft_atoi(argv[1]);
	if (check_pid(server_pid) == 1)
	{
		i = 0;
		while (argv[2][i])
		{
			send_bit(server_pid, argv[2][i]);
			i++;
		}
		send_bit(server_pid, '\0');
	}
	return (0);
}
