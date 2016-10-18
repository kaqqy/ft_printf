/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 20:33:57 by jshi              #+#    #+#             */
/*   Updated: 2016/10/17 17:02:51 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_wstrlen(wchar_t *str);
void		ft_wputchar(wchar_t c);
void		ft_wputstr(wchar_t *str);
wchar_t		*str_to_wstr(char *str);
wchar_t		*wstr_to_wstr(wchar_t *str);
void		prepend_char(wchar_t **str, wchar_t c, int min_len);
void		append_char(wchar_t **str, wchar_t c, int min_len);
void		prepend_str(wchar_t **dst, wchar_t *src);
void		append_str(wchar_t **dst, wchar_t *src);
wchar_t		*ft_itoa_base(uintmax_t n, int base, char *letters);
int			print_signed_decimal(va_list *args);
int			print_unsigned_decimal(va_list *args);
int			print_hex(va_list *args, char *letters);
int			print_pointer(va_list *args);
int			print_octal(va_list *args);
int			print_string(va_list *args);
int			print_char(va_list *args);
int			print_percent(void);
extern int	g_hashtag;
extern int	g_zero;
extern int	g_minus;
extern int	g_plus;
extern int	g_space;
extern int	g_minwid;
extern int	g_prec;
extern int	g_lenmod;
extern int	g_sign;
#endif
