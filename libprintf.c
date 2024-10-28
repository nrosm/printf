/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-09 11:14:19 by nroson-m          #+#    #+#             */
/*   Updated: 2024-10-09 11:14:19 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base(unsigned long long n, char *base, int len, int *counter)
{
	char	nb;

	if (n >= (unsigned long long)len)
	{
		ft_print_base(n / len, base, len, counter);
	}
	nb = base[n % len];
	*counter += write(1, &nb, 1);
}

void	ft_putnbr(int n, int *counter)
{
	long long int	nb;
	char			c;

	nb = n;
	if (nb < 0)
	{
		*counter += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, counter);
		ft_putnbr(nb % 10, counter);
	}
	else
	{
		c = nb + '0';
		*counter += write(1, &c, 1);
	}
}

void	ft_printstr(char *str, int *counter)
{
	if (!str)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (*str)
		*counter += write(1, str++, 1);
}
