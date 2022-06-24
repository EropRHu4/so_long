/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:16:08 by syule             #+#    #+#             */
/*   Updated: 2022/06/24 17:16:09 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_number(unsigned long int num, int *len, int base, char x)
{
	char	c;

	if (num >= (unsigned long)base)
		print_unsigned_number(num / base, len, base, x);
	c = num % base;
	if (c > 9)
		c = c - 10 + x;
	else
		c = c + '0';
	*len += write(1, &c, 1);
}

int	print_pointer(void *p)
{
	unsigned long	number;
	int				len;

	len = 0;
	p = (char *)p;
	number = (unsigned long int)p;
	len += write(1, "0x", 2);
	print_unsigned_number(number, &len, 16, 'a');
	return (len);
}

int	print_decimal(int number)
{
	long int	num;
	int			len;

	len = 0;
	if (number < 0)
	{
		len += write(1, "-", 1);
		num = (long int)number * -1;
	}
	else
		num = number;
	print_unsigned_number(num, &len, 10, 'a');
	return (len);
}

int	print_unsigned_int(int num)
{
	unsigned int	number;
	int				len;

	len = 0;
	number = (unsigned int)num;
	print_unsigned_number(number, &len, 10, 'a');
	return (len);
}

int	print_hexadecimal(int num, char x)
{
	unsigned int	number;
	int				len;

	len = 0;
	number = (unsigned int)num;
	print_unsigned_number(number, &len, 16, x);
	return (len);
}
