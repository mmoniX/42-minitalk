/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:43:09 by mmonika           #+#    #+#             */
/*   Updated: 2024/12/06 15:54:48 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	sigcon_handler(int mysignal)
{
	if (mysignal == SIGUSR1)
		ft_printf("\e[1;32mThank you for your message 😊\e[0m\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sca;
	int					server_pid;

	sca.sa_handler = sigcon_handler;
	sigemptyset(&sca.sa_mask);
	sca.sa_flags = 0;
	sigaction(SIGUSR1, &sca, NULL);
	if (argc == 3 && argv[2][0] != '\0')
	{
		signal(SIGUSR1, sigcon_handler);
		server_pid = ft_atoi(argv[1]);
		if (check_pid(server_pid) == 1)
			send_bit(server_pid, argv[2]);
	}
	else
	{
		ft_printf ("\e[1;31myou need three arguments. Try again.\e[0m\n");
		ft_printf ("\e[1;31m<./client> <PID> <message>\e[0m");
		exit(0);
	}
	return (0);
}
