/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:05:10 by evalenti          #+#    #+#             */
/*   Updated: 2023/07/08 11:59:42 by evalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	if (spec == 's')
		count += print_str(va_arg(ap, char *));
	if (spec == 'p')
		count += print_pointer(va_arg(ap, unsigned long), 16, spec);
	if (spec == 'd' || spec == 'i')
		count += print_number(va_arg(ap, int));
	if (spec == 'u')
		count += print_base(va_arg(ap, unsigned int), 10, spec);
	if (spec == 'x' || spec == 'X')
		count += print_base(va_arg(ap, unsigned int), 16, spec);
	if (spec == '%')
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *format, ...)

{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += check_specifier(*++format, ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
