/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:57:11 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 20:51:47 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static uintmax_t	fix_sign(intmax_t a)
{
	if (a < 0)
	{
		g_sign = -1;
		return ((uintmax_t)(-a));
	}
	g_sign = 1;
	return ((uintmax_t)a);
}

static int			apply_flags(wchar_t *str)
{
	int		ret;

	prepend_char(&str, '0', g_prec);
	if (g_zero == 1 && g_minus == 0 && g_prec < 0)
	{
		if (g_sign == 0 || (g_plus == 0 && g_space == 0 && g_sign == 1))
			prepend_char(&str, '0', g_minwid);
		else
			prepend_char(&str, '0', g_minwid - 1);
	}
	if (g_sign == -1)
		prepend_str(&str, L"-");
	else if (g_plus == 1 && g_sign == 1)
		prepend_str(&str, L"+");
	else if (g_space == 1 && g_sign == 1)
		prepend_str(&str, L" ");
	if (g_minus == 1)
		append_char(&str, ' ', g_minwid);
	else
		prepend_char(&str, ' ', g_minwid);
	ret = ft_wstrlen(str);
	ft_wputstr(str);
	free(str);
	return (ret);
}

int					print_signed_decimal(va_list *args)
{
	intmax_t	a;

	a = 0;
	if (g_lenmod == 1)
		a = (char)va_arg(*args, int);
	else if (g_lenmod == 2)
		a = (short)va_arg(*args, int);
	else if (g_lenmod == 3)
		a = va_arg(*args, long);
	else if (g_lenmod == 4)
		a = va_arg(*args, long long);
	else if (g_lenmod == 5)
		a = va_arg(*args, intmax_t);
	else if (g_lenmod == 6)
	{
		a = va_arg(*args, size_t);
		if (sizeof(size_t) < sizeof(intmax_t) &&
				a >= ((intmax_t)1) << (8 * sizeof(size_t) - 1))
			a -= (((intmax_t)1) << (8 * sizeof(size_t) - 1));
	}
	else
		a = va_arg(*args, int);
	return (apply_flags(ft_itoa_base(fix_sign(a), 10, "0123456789")));
}

int					print_unsigned_decimal(va_list *args)
{
	uintmax_t	a;

	a = 0;
	if (g_lenmod == 1)
		a = (unsigned char)va_arg(*args, unsigned int);
	else if (g_lenmod == 2)
		a = (unsigned short)va_arg(*args, unsigned int);
	else if (g_lenmod == 3)
		a = va_arg(*args, unsigned long);
	else if (g_lenmod == 4)
		a = va_arg(*args, unsigned long long);
	else if (g_lenmod == 5)
		a = va_arg(*args, uintmax_t);
	else if (g_lenmod == 6)
		a = va_arg(*args, size_t);
	else
		a = va_arg(*args, unsigned int);
	return (apply_flags(ft_itoa_base(a, 10, "0123456789")));
}
