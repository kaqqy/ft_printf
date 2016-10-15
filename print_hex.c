/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:06:26 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 21:40:59 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	apply_flags(wchar_t *str, wchar_t *prefix)
{
	int		ret;
	char	first;

	first = *(char*)str;
	prepend_char(&str, '0', g_prec);
	if (g_zero == 1 && g_minus == 0 && g_prec < 0)
	{
		if (g_hashtag == 1 && first != '0')
			prepend_char(&str, '0', g_minwid - 2);
		else
			prepend_char(&str, '0', g_minwid);
	}
	if (g_hashtag == 1 && first != '0')
		prepend_str(&str, prefix);
	if (g_minus == 1)
		append_char(&str, ' ', g_minwid);
	else
		prepend_char(&str, ' ', g_minwid);
	ret = ft_wstrlen(str);
	ft_wputstr(str);
	free(str);
	return (ret);
}

int			print_hex(va_list *args, char *letters)
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
	if (letters[10] == 'a')
		return (apply_flags(ft_itoa_base(a, 16, letters), L"0x"));
	return (apply_flags(ft_itoa_base(a, 16, letters), L"0X"));
}

int			print_pointer(va_list *args)
{
	uintmax_t	a;

	g_hashtag = 1;
	a = (uintmax_t)va_arg(*args, void*);
	return (apply_flags(ft_itoa_base(a, 16, "0123456789abcdef"), L"0x"));
}
