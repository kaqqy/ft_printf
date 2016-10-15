/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 18:24:25 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 20:23:15 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		g_hashtag;
int		g_zero;
int		g_minus;
int		g_plus;
int		g_space;
int		g_minwid;
int		g_prec;
int		g_lenmod;
int		g_sign;

void	set_flags(char **pos)
{
	g_hashtag = 0;
	g_zero = 0;
	g_minus = 0;
	g_plus = 0;
	g_space = 0;
	g_sign = 0;
	while (**pos == '#' || **pos == '0' || **pos == '-' || **pos == '+' ||
			**pos == ' ')
	{
		if (**pos == '#')
			g_hashtag = 1;
		else if (**pos == '0')
			g_zero = 1;
		else if (**pos == '-')
			g_minus = 1;
		else if (**pos == '+')
			g_plus = 1;
		else if (**pos == ' ')
			g_space = 1;
		(*pos)++;
	}
}

void	set_minwid(char **pos)
{
	g_minwid = 0;
	while (**pos >= '0' && **pos <= '9')
	{
		g_minwid = g_minwid * 10 + **pos - '0';
		(*pos)++;
	}
}

void	set_prec(char **pos)
{
	g_prec = -1;
	if (**pos != '.')
		return ;
	g_prec = 0;
	(*pos)++;
	while (**pos >= '0' && **pos <= '9')
	{
		g_prec = g_prec * 10 + **pos - '0';
		(*pos)++;
	}
}

void	set_lenmod(char **pos)
{
	g_lenmod = 0;
	if ((*pos)[0] == 'h' && (*pos)[1] == 'h')
		g_lenmod = 1;
	else if ((*pos)[0] == 'h')
		g_lenmod = 2;
	else if ((*pos)[0] == 'l' && (*pos)[1] != 'l')
		g_lenmod = 3;
	else if ((*pos)[0] == '.')
		g_lenmod = 4;
	else if ((*pos)[0] == 'j')
		g_lenmod = 5;
	else if ((*pos)[0] == 'z')
		g_lenmod = 6;
	if (g_lenmod == 1 || g_lenmod == 4)
		(*pos) += 2;
	else if (g_lenmod > 0)
		(*pos)++;
}

int		print_conversion(char **pos, va_list *args)
{
	set_flags(pos);
	set_minwid(pos);
	set_prec(pos);
	set_lenmod(pos);
	(*pos)++;
	if ((*pos)[-1] >= 'A' && (*pos)[-1] <= 'Z')
		g_lenmod = 3;
	if ((*pos)[-1] == 'd' || (*pos)[-1] == 'i' || (*pos)[-1] == 'D')
		return (print_signed_decimal(args));
	if ((*pos)[-1] == 'u' || (*pos)[-1] == 'U')
		return (print_unsigned_decimal(args));
	if ((*pos)[-1] == 'o' || (*pos)[-1] == 'O')
		return (print_octal(args));
	if ((*pos)[-1] == 'x')
		return (print_hex(args, "0123456789abcdef"));
	if ((*pos)[-1] == 'X')
		return (print_hex(args, "0123456789ABCDEF"));
	if ((*pos)[-1] == 's' || (*pos)[-1] == 'S')
		return (print_string(args));
	if ((*pos)[-1] == 'c' || (*pos)[-1] == 'C')
		return (print_char(args));
	if ((*pos)[-1] == 'p')
		return (print_pointer(args));
	(*pos)--;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		num_char;
	char	*pos;
	va_list	args;

	num_char = 0;
	pos = (char*)format;
	va_start(args, format);
	while (*pos)
	{
		if (*pos != '%')
		{
			write(1, pos, 1);
			num_char++;
			pos++;
		}
		else
		{
			pos++;
			num_char += print_conversion(&pos, &args);
		}
	}
	va_end(args);
	return (num_char);
}
