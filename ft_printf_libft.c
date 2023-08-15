/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:03:08 by evalenti          #+#    #+#             */
/*   Updated: 2023/07/08 12:01:51 by evalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(const char c)
{
	return (write(1, &c, 1));
}

int	print_str(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (print_str("(null)"));
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	print_base(unsigned long nbr, int base, char spec)
{
	int		count;
	char	*symbols;

	count = 0;
	if (spec == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (nbr >= (unsigned long)base)
	{
		count += print_base(nbr / base, base, spec);
		count += print_base(nbr % base, base, spec);
	}
	else
		count += print_char(symbols[nbr]);
	return (count);
}

int	print_number(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += print_str("-2147483648");
		return (count);
	}
	if (nbr < 0)
	{
		count += print_char('-');
		nbr *= -1;
	}
	count += print_base(nbr, 10, 'x');
	return (count);
}

int	print_pointer(unsigned long nbr, int base, char spec)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count += print_str("(nil)");
	else
	{
		count += print_str("0x");
		count += print_base(nbr, base, spec);
	}
	return (count);
}
