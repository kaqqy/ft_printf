/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 21:03:03 by jshi              #+#    #+#             */
/*   Updated: 2016/10/28 21:16:11 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		print_color_text(t_flags *f)
{
	char	*str;
	char	*num;
	int		ret;

	str = ft_strdup("\e[38;2;");
	num = ft_itoa_base(((f->minwid) >> 16) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base(((f->minwid) >> 8) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base((f->minwid) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, "m");
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_color_bg(t_flags *f)
{
	char	*str;
	char	*num;
	int		ret;

	str = ft_strdup("\e[48;2;");
	num = ft_itoa_base(((f->minwid) >> 16) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base(((f->minwid) >> 8) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base((f->minwid) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, "m");
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_color_reset(void)
{
	ft_putstr("\e[0m");
	return (4);
}
