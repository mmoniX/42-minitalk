/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonika <mmonika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:54:07 by mmonika           #+#    #+#             */
/*   Updated: 2025/07/22 20:07:13 by mmonika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "42-printf/ft_printf.h"

int		ft_atoi(const char *str);
int		check_pid(pid_t server_pid);
void	ft_bit(pid_t server_pid, char c);
void	send_bit(pid_t server_pid, char *text);

#endif