/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:56:47 by jshi              #+#    #+#             */
/*   Updated: 2016/10/28 20:24:25 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	if (!str)
		return ;
	len = ft_strlen(str);
	i = -1;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

void	empty_string(char **str)
{
	free(*str);
	*str = (char*)malloc(sizeof(**str));
	(*str)[0] = '\0';
}
