/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:42:55 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/22 16:47:59 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			len = ft_str("-2147483648");
			return (len);
		}
		if (ft_char('-') < 0)
			return (-1);
		len++;
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_nbr(nb / 10);
	if (len != -1)
		len += ft_char("0123456789"[nb % 10]);
	return (len);
}
