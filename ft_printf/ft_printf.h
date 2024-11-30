/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:45:20 by mmonika           #+#    #+#             */
/*   Updated: 2024/10/22 13:25:40 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int	ft_arguments(va_list args, char x);
int	ft_printf(const char *input, ...);
int	ft_char(char c);
int	ft_str(char *str);
int	ft_pointer(void *ptr);
int	ft_nbr(int nb);
int	ft_unsigned_nbr(unsigned int nb);
int	ft_lowhex(unsigned int nb);
int	ft_caphex(unsigned int nb);

#endif