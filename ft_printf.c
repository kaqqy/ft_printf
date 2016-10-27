/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 20:06:35 by jshi              #+#    #+#             */
/*   Updated: 2016/10/27 02:33:37 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	print_conversion_p2(char **pos, va_list *args, t_flags *f)
{
	if ((*pos)[-1] == 'f' || (*pos)[-1] == 'F')
		return (print_float(args, f));
	if ((*pos)[-1] == 'e' || (*pos)[-1] == 'E')
		return (print_float_e(args, f));
/*	if ((*pos)[-1] == 'g' || (*pos)[-1] == 'G')
		return (print_float_g(args, f));
	if ((*pos)[-1] == 'a' || (*pos)[-1] == 'A')
		return (print_float_hex(args, f));
	if ((*pos)[-1] == 'n')
		return (store_numchar(args, f));*/
	if ((*pos)[-1] != '\0')
		return (print_not_flag(f));
	(*pos)--;
	return (0);
}

static int	print_conversion(char **pos, va_list *args, t_flags *f)
{
	set_arg(pos, args, f);
	set_flags(pos, f);
	set_minwid(pos, args, f);
	set_prec(pos, args, f);
	set_lenmod(pos, f);
	f->conv = (*pos)[0];
	(*pos)++;
	if ((*pos)[-1] == 'd' || (*pos)[-1] == 'i' || (*pos)[-1] == 'D')
		return (print_decimal(get_signed_int(args, f, 10), f));
	if ((*pos)[-1] == 'u' || (*pos)[-1] == 'U')
		return (print_decimal(get_unsigned_int(args, f, 10), f));
	if ((*pos)[-1] == 'o' || (*pos)[-1] == 'O')
		return (print_octal(get_unsigned_int(args, f, 8), f));
	if ((*pos)[-1] == 'x' || (*pos)[-1] == 'X')
		return (print_hex(get_unsigned_int(args, f, 16), f, 0));
	if ((*pos)[-1] == 'p')
		return (print_hex(get_unsigned_int(args, f, 16), f, 1));
	if ((*pos)[-1] == 's' || (*pos)[-1] == 'S')
		return (print_string(args, f));
	if ((*pos)[-1] == 'c' || (*pos)[-1] == 'C')
		return (print_char(args, f));
	return (print_conversion_p2(pos, args, f));
}

int			ft_printf(const char *format, ...)
{
	int		num_char;
	char	*pos;
	va_list	args;
	t_flags	f;

	num_char = 0;
	pos = (char*)format;
	va_start(args, format);
	va_copy(f.arg_start, args);
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
			num_char += print_conversion(&pos, &args, &f);
		}
	}
	va_end(args);
	return (num_char);
}
