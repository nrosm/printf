/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-10 09:37:00 by nroson-m          #+#    #+#             */
/*   Updated: 2024-10-10 09:37:00 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	its_char(char const *type, va_list argptr, int *counter)
{
	int	i;

	if (*type == 'c')
	{
		i = va_arg (argptr, int);
		*counter += write (1, &i, 1);
	}
	else if (*type == 's')
	{
		ft_printstr (va_arg(argptr, char *), counter);
	}
}

static void	its_number(char const *type, va_list argptr, int *counter)
{
	if (*type == 'd' || *type == 'i')
		ft_putnbr(va_arg(argptr, int), counter);
	else if (*type == 'u')
		ft_print_base(va_arg(argptr, unsigned int), "0123456789", 10, counter);
	else if (*type == 'x')
		ft_print_base(va_arg(argptr, unsigned int),
			"0123456789abcdef", 16, counter);
	else if (*type == 'X')
		ft_print_base(va_arg(argptr, unsigned int),
			"0123456789ABCDEF", 16, counter);
}

static void	its_pointer(char const *type, va_list argptr, int *counter)
{
	unsigned long long	dir;

	if (*type == 'p')
	{
		dir = va_arg(argptr, unsigned long long);
		if (dir == 0)
		{
			*counter += write (1, "(nil)", 5);
			return ;
		}
		*counter += write(1, "0x", 2);
		ft_print_base(dir, "0123456789abcdef", 16, counter);
	}
}

static void	organize_type(char const *type, va_list argptr, int *counter)
{
	if (*type == 'c' || *type == 's')
		its_char(type, argptr, counter);
	else if (*type == 'd' || *type == 'i' || *type == 'u'
		|| *type == 'x' || *type == 'X')
		its_number(type, argptr, counter);
	else if (*type == 'p')
		its_pointer(type, argptr, counter);
	else if (*type == '%')
		*counter += write(1, "%", 1);
}

int	ft_printf(char const *type, ...)
{
	int		counter;
	va_list	argptr;

	counter = 0;
	va_start(argptr, type);
	while (*type)
	{
		if (*type == '%' && *(type + 1))
			organize_type(++type, argptr, &counter);
		else
			counter += write(1, type, 1);
		++type;
	}
	va_end(argptr);
	return (counter);
}
