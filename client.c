/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:21:59 by mmonika           #+#    #+#             */
/*   Updated: 2024/12/01 17:22:08 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int argc, char *argv[])
{
	int		server_pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
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