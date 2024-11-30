/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:06:03 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/22 17:25:54 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	uintptr_t	nb;
	int			len;

	len = 0;
	if (ptr == NULL)
		return (ft_char('0'));
	nb = (uintptr_t)ptr;
	if (nb >= 16)
		len += ft_pointer((void *)(nb / 16));
	len += ft_char("0123456789abcdef"[nb % 16]);
	return (len);
}
