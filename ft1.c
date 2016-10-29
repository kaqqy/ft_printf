/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:09:10 by jshi              #+#    #+#             */
/*   Updated: 2016/10/28 18:57:57 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
		return (NULL);
	dup[len] = '\0';
	while (len--)
		dup[len] = str[len];
	return (dup);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

char	*ft_strsub(char *str, int start, int len)
{
	int		slen;
	char	*sub;

	if (!str || (slen = ft_strlen(str)) < start + len ||
			!(sub = (char*)malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = str[start + len];
	return (sub);
}

void	ft_strtoupper(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}
