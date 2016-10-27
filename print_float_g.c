/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 01:50:49 by jshi              #+#    #+#             */
/*   Updated: 2016/10/27 02:04:26 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		print_float_g(va_list *args, t_flags *f)
{
	long double	a;
	int			i;

	if (f->lenmod == 7)
		a = va_arg(*args, long double);
	else
		a = va_arg(*args, double);
	f->sign = a < 0 ? -1 : 1;
	if ((i = handle_nan(a, f, 0)) >= 0)
		return (i);
	f->prec = (f->prec < 0) ? 6 : f->prec + !f->prec;
	return (0);
}
