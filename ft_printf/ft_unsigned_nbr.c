/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:41:35 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/22 16:58:21 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		return (-1);
	if (nb >= 10)
		len += ft_unsigned_nbr(nb / 10);
	if (len != -1)
		len += ft_char("0123456789"[nb % 10]);
	return (len);
}
