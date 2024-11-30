/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caphex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:45 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/22 17:06:29 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_caphex(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_caphex(nb / 16);
	if (len != -1)
		len += ft_char("0123456789ABCDEF"[nb % 16]);
	return (len);
}
