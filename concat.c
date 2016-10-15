/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 01:16:42 by jshi              #+#    #+#             */
/*   Updated: 2016/10/14 20:18:09 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	prepend_char(wchar_t **str, wchar_t c, int min_len)
{
	int		len;
	wchar_t	*new;

	len = ft_wstrlen(*str);
	if (len >= min_len)
		return ;
	new = (wchar_t*)malloc(sizeof(*new) * (min_len + 1));
	if (!new)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new[min_len] = '\0';
	while (len-- > 0)
		new[--min_len] = (*str)[len];
	while (min_len--)
		new[min_len] = c;
	free(*str);
	*str = new;
}

void	append_char(wchar_t **str, wchar_t c, int min_len)
{
	int		len;
	wchar_t	*new;

	len = ft_wstrlen(*str);
	if (len >= min_len)
		return ;
	new = (wchar_t*)malloc(sizeof(*new) * (min_len + 1));
	if (!new)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new[min_len] = '\0';
	while (min_len > len)
		new[--min_len] = c;
	while (min_len--)
		new[min_len] = (*str)[min_len];
	free(*str);
	*str = new;
}

void	prepend_str(wchar_t **dst, wchar_t *src)
{
	int		dst_len;
	int		src_len;
	wchar_t	*cat;

	dst_len = ft_wstrlen(*dst);
	src_len = ft_wstrlen(src);
	cat = (wchar_t*)malloc(sizeof(*cat) * (dst_len + src_len + 1));
	if (!cat)
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	cat[dst_len + src_len] = '\0';
	while (dst_len--)
		cat[dst_len + src_len] = (*dst)[dst_len];
	while (src_len--)
		cat[src_len] = src[src_len];
	free(*dst);
	*dst = cat;
}

void	append_str(wchar_t **dst, wchar_t *src)
{
	int		dst_len;
	int		src_len;
	wchar_t	*cat;

	dst_len = ft_wstrlen(*dst);
	src_len = ft_wstrlen(src);
	cat = (wchar_t*)malloc(sizeof(*cat) * (dst_len + src_len + 1));
	if (!cat)
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	cat[dst_len + src_len] = '\0';
	while (src_len--)
		cat[dst_len + src_len] = src[src_len];
	while (dst_len--)
		cat[dst_len] = (*dst)[dst_len];
	free(*dst);
	*dst = cat;
}
