/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:48:33 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/25 12:32:56 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arguments(va_list args, char x)
{
	int	res;

	res = 0;
	if (x == 'c')
		res = ft_char(va_arg(args, int));
	else if (x == 's')
		res = ft_str(va_arg(args, char *));
	else if (x == 'p')
	{
		res = ft_str("0x");
		if (res != -1)
			res += ft_pointer(va_arg(args, void *));
	}
	else if (x == 'd' || x == 'i')
		res = ft_nbr(va_arg(args, int));
	else if (x == 'u')
		res = ft_unsigned_nbr(va_arg(args, unsigned int));
	else if (x == 'x')
		res = ft_lowhex(va_arg(args, unsigned int));
	else if (x == 'X')
		res = ft_caphex(va_arg(args, unsigned int));
	else if (x == '%')
		res = ft_char('%');
	return (res);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%' && len != -1)
		{
			len += ft_arguments(args, input[i + 1]);
			i++;
		}
		else if (len != -1)
			len += ft_char (input[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	int res1 = ft_printf("%%\n");
// 	int res2 = printf("%%\n");
// 	printf("res1: %i\n", res1);
// 	printf("res2: %i\n", res2);
// 	return (0);
// }