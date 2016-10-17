/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:13:43 by jshi              #+#    #+#             */
/*   Updated: 2016/10/17 16:45:06 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static void		ft_wstrsub(wchar_t **str, int len)
{
	wchar_t	*sub;

	sub = (wchar_t*)malloc(sizeof(**str) * (len + 1));
	if (!sub)
		return ;
	sub[len] = '\0';
	while (len--)
		sub[len] = (*str)[len];
	free(*str);
	*str = sub;
}

static int		apply_flags(wchar_t *str, int is_percent)
{
	int		len;

	if (g_prec >= 0 && g_prec < ft_wstrlen(str) && !is_percent)
		ft_wstrsub(&str, g_prec);
	if (g_minus == 1)
		append_char(&str, ' ', g_minwid);
	else if (g_zero == 1)
		prepend_char(&str, '0', g_minwid);
	else
		prepend_char(&str, ' ', g_minwid);
	len = ft_wstrlen(str);
	ft_wputstr(str);
	free(str);
	return (len);
}

int				print_string(va_list *args)
{
	wchar_t	*str;

	if (g_lenmod == 3)
		str = wstr_to_wstr(va_arg(*args, wchar_t*));
	else
		str = str_to_wstr(va_arg(*args, char*));
	return (apply_flags(str, 0));
}

int				print_char(va_list *args)
{
	wchar_t	c;
	wchar_t	*str;

	if (g_lenmod == 3)
		c = va_arg(*args, wchar_t);
	else
		c = (char)va_arg(*args, int);
	str = (wchar_t*)malloc(sizeof(*str) * 2);
	if (!str)
		return (0);
	str[0] = c;
	str[1] = '\0';
	return (apply_flags(str, 0));
}

int				print_percent(void)
{
	wchar_t	*str;

	str = (wchar_t*)malloc(sizeof(*str) * 2);
	str[0] = '%';
	str[1] = '\0';
	return (apply_flags(str, 1));
}
