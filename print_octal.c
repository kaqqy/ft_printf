/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:49:42 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 16:55:42 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	apply_flags(wchar_t *str)
{
	int		ret;

	prepend_char(&str, '0', g_prec);
	if (g_zero == 1 && g_minus == 0 && g_prec < 0)
	{
		if (g_hashtag == 1)
			prepend_char(&str, '0', g_minwid - 1);
		else
			prepend_char(&str, '0', g_minwid);
	}
	if (g_hashtag == 1)
		prepend_str(&str, L"0");
	if (g_minus == 1)
		append_char(&str, ' ', g_minwid);
	else
		prepend_char(&str, ' ', g_minwid);
	ret = ft_wstrlen(str);
	ft_wputstr(str);
	free(str);
	return (ret);
}

int			print_octal(va_list *args)
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
	return (apply_flags(ft_itoa_base(a, 8, "01234567")));
}
