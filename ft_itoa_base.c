/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 22:49:18 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 19:33:39 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

wchar_t	*ft_itoa_base(uintmax_t n, int base, char *letters)
{
	int			len;
	uintmax_t	pow;
	wchar_t		*str;

	len = 1;
	pow = 1;
	while (n / pow >= (uintmax_t)base)
	{
		pow *= base;
		len++;
	}
	str = (wchar_t*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (!n)
		str[len] = '0';
	while (n)
	{
		str[len--] = letters[n % base];
		n /= base;
	}
	return (str);
}
