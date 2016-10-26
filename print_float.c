/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:27:10 by jshi              #+#    #+#             */
/*   Updated: 2016/10/26 15:22:06 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*round_float(char *str, int prec)
{
	int		i;

	i = 6000 - prec;
	if (str[i - 1] >= '5')
		str[i]++;
	while (str[i] == '0' + 10)
	{
		str[i] = '0';
		i++;
		str[i]++;
	}
	return (str);
}

static int	handle_nan(long double a, t_flags *f)
{
	long double	nan;
	long long	*x;
	long long	*y;
	int			ret;
	char		*str;

	nan = 0.0 / 0.0;
	x = (long long*)&nan;
	y = (long long*)&a;
	if (x[0] == y[0] && x[1] == y[1])
		str = ft_strdup("nan");
	else if (a == 1.0 / 0.0)
		str = ft_strdup("inf");
	else if (a == -1.0 / 0.0)
		str = ft_strdup("-inf");
	else
		return (-1);
	if (f->conv == 'F')
		ft_strtoupper(str);
	ft_putstr(str);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}

static int	apply_flags(char *inte, char *frac, t_flags *f)
{
	int		ret;

	insert_commas(&inte, f->apos);
	if (f->pound == 1 || ft_strlen(frac) > 0)
		append_str(&inte, ".");
	append_str(&inte, frac);
	free(frac);
	if (f->sign == -1)
		prepend_str(&inte, "-");
	else if (f->plus == 1)
		prepend_str(&inte, "+");
	else if (f->space == 1)
		prepend_str(&inte, " ");
	prepend_char(&inte, ' ', f->minwid);
	ret = ft_strlen(inte);
	ft_putstr(inte);
	free(inte);
	return (ret);
}

int			print_float(va_list *args, t_flags *f)
{
	long double	a;
	char		*str;
	char		*frac;
	char		*inte;
	int			i;

	if (f->lenmod == 7)
		a = va_arg(*args, long double);
	else
		a = va_arg(*args, double);
	if ((i = handle_nan(a, f)) >= 0)
		return (i);
	if (f->prec < 0)
		f->prec = 6;
	str = round_float(get_float(a), f->prec);
	f->sign = a < 0 ? -1 : 1;
	frac = ft_strsub(str, 6000 - f->prec, f->prec);
	ft_strrev(frac);
	i = 11999;
	while (str[i] == '0' && i >= 5999)
		i--;
	inte = ft_strsub(str, 6000, i - 5999);
	ft_strrev(inte);
	free(str);
	return (apply_flags(inte, frac, f));
}
