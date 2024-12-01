/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:56:39 by mmonika           #+#    #+#             */
/*   Updated: 2024/12/01 15:22:53 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

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
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
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
		ft_printf("\033[1;31mwrong pid. type carefully...\033[0m\n");
		exit (0);
	}
	return (1);
}

void	ft_bit(pid_t server_pid, char c)
{
	int	bit;

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

void	send_bit(pid_t server_pid, char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\0')
	{
		ft_bit(server_pid, text[i]);
		i++;
	}
	ft_bit(server_pid, '\0');
}
