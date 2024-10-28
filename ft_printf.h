/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 11:36:19 by nroson-m          #+#    #+#             */
/*   Updated: 2024-10-09 11:36:19 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *type, ...);
void	ft_print_base(unsigned long long n, char *base, int len, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_printstr(char *str, int *counter);

#endif
