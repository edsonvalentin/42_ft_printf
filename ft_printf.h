/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:10:24 by evalenti          #+#    #+#             */
/*   Updated: 2023/07/08 11:57:25 by evalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* 
*** headers ***
*/

# include <stdarg.h>
# include <unistd.h>

/*
*** functions ***
*/

int	print_char(const char c);
int	print_str(const char *str);
int	print_number(int nbr);
int	print_base(unsigned long nbr, int base, char spec);
int	print_pointer(unsigned long nbr, int base, char spec);
int	check_specifier(char spec, va_list ap);
int	ft_printf(const char *format, ...);

#endif
