/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:21:59 by mmonika           #+#    #+#             */
/*   Updated: 2024/11/25 13:29:34 by mmonika          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		ft_printf ("you need three arguments. Try again.");
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	if (check_pid(server_pid) == 1)
	{
		while (argv[2][i])
		{
			send_bit(server_pid, argv[2][i]);
			i++;
		}
		send_bit(server_pid, '\0');
	}
	return (0);
}

/*
SIGUSR1 send 1;
SIGUSR2 send 0;

h in binary 0110 1000 ;
(h >> 7) & 1 ; (0 1101000 >> 7) & 1 ; (0 & 1) ; 0 ; send SIGUSR2
(h >> 6) & 1 ; (01 101000 >> 6) & 1 ; (1 & 1) ; 1 ; send SIGUSR1
(h >> 5) & 1 ; (011 01000 >> 5) & 1 ; (1 & 1) ; 1 ; send SIGUSR1
(h >> 4) & 1 ; (0110 1000 >> 4) & 1 ; (0 & 1) ; 0 ; send SIGUSR2
(h >> 3) & 1 ; (01101 000 >> 3) & 1 ; (1 & 1) ; 1 ; send SIGUSR1
(h >> 2) & 1 ; (011010 00 >> 2) & 1 ; (0 & 1) ; 0 ; send SIGUSR2
(h >> 1) & 1 ; (0110100 0 >> 1) & 1 ; (0 & 1) ; 0 ; send SIGUSR2
(h >> 0) & 1 ; (01101000  >> 0) & 1 ; (0 & 1) ; 0 ; send SIGUSR2
e in binary 0110 0101 ; (e >> 7) & 1;
l in binary 0110 1100
l in binary 0110 1100
o in binary 0110 1111
*/