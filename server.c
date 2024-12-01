/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:20:07 by mmonika           #+#    #+#             */
/*   Updated: 2024/12/01 15:13:00 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	sig_handler(int mysignal)
{
	static char	c = 0;
	static int	i = 0;

	c = (c << 1) | (mysignal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("\033[1;32mHi! welcome to my terminal 😊\033[0m\n");
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}

/*
	x << 2 means pushing x for 2 bytes & add 2 zeros in the end.
	9 in bit 		0000 1001
	9 << 2 will be	00 100100

	x >> 2 means pushing x for 2 bytes & add 2 zeros in the begining.
	9 in bit 		0000 1001
	9 >> 2 will be	000000 10
	
here it will do the reverse engineering
SIGUSR1 send 1;
SIGUSR2 send 0;

h in binary 0110 1000 ;
(h >> 7) & 1 ; (01101000 >> 7) & 1 ; (0000000 0 & 1) ; 0 ; send SIGUSR2
(h >> 6) & 1 ; (01101000 >> 6) & 1 ; (000000 01 & 1) ; 1 ; send SIGUSR1
(h >> 5) & 1 ; (01101000 >> 5) & 1 ; (00000 011 & 1) ; 1 ; send SIGUSR1
(h >> 4) & 1 ; (01101000 >> 4) & 1 ; (0000 0110 & 1) ; 0 ; send SIGUSR2
(h >> 3) & 1 ; (01101000 >> 3) & 1 ; (000 01101 & 1) ; 1 ; send SIGUSR1
(h >> 2) & 1 ; (01101000 >> 2) & 1 ; (00 011010 & 1) ; 0 ; send SIGUSR2
(h >> 1) & 1 ; (01101000 >> 1) & 1 ; (0 0110100 & 1) ; 0 ; send SIGUSR2
(h >> 0) & 1 ; (01101000 >> 0) & 1 ; ( 01101000 & 1) ; 0 ; send SIGUSR2

i = 0; c = 00000000
received SIGUSR2 ; 0 ; (c << 1) | 0 ; (0000000 0 << 1) | 0 ; 0000000 0 ; i = 1
received SIGUSR1 ; 1 ; (c << 1) | 1 ; (000000 01 << 1) | 1 ; 000000 01 ; i = 2
received SIGUSR1 ; 1 ; (c << 1) | 1 ; (00000 011 << 1) | 1 ; 00000 011 ; i = 3
received SIGUSR2 ; 0 ; (c << 1) | 0 ; (0000 0110 << 1) | 0 ; 0000 0110 ; i = 4
received SIGUSR1 ; 1 ; (c << 1) | 1 ; (000 01101 << 1) | 1 ; 000 01101 ; i = 5
received SIGUSR2 ; 0 ; (c << 1) | 0 ; (00 011010 << 1) | 0 ; 00 011010 ; i = 6
received SIGUSR2 ; 0 ; (c << 1) | 0 ; (0 0110100 << 1) | 0 ; 0 0110100 ; i = 7
received SIGUSR2 ; 0 ; (c << 1) | 0 ; (01101000  << 1) | 0 ;  01101000 ; i = 8
so c == 01101000 which is 104 in decimal i.e. h in ascii ; print 'h'
*/