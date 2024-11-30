/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:49:31 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/22 17:06:18 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhex(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_lowhex(nb / 16);
	if (len != -1)
		len += ft_char("0123456789abcdef"[nb % 16]);
	return (len);
}
