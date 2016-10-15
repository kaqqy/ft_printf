/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:35:38 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 21:32:09 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_wstrlen(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_wputchar(wchar_t c)
{
	write(1, &c, 1);
}

void	ft_wputstr(wchar_t *str)
{
	int		len;
	int		i;

	len = ft_wstrlen(str);
	i = -1;
	while (++i < len)
		ft_wputchar(str[i]);
}

wchar_t	*str_to_wstr(char *str)
{
	wchar_t	*wstr;
	int		len;

	len = 0;
	while (str[len])
		len++;
	wstr = (wchar_t*)malloc(sizeof(*wstr) * (len + 1));
	if (!wstr)
		return (NULL);
	wstr[len] = '\0';
	while (len--)
		wstr[len] = str[len];
	return (wstr);
}

wchar_t	*wstr_to_wstr(wchar_t *str)
{
	wchar_t	*wstr;
	int		len;

	len = ft_wstrlen(str);
	wstr = (wchar_t*)malloc(sizeof(*wstr) * (len + 1));
	if (!wstr)
		return (NULL);
	wstr[len] = '\0';
	while (len--)
		wstr[len] = str[len];
	return (wstr);
}
