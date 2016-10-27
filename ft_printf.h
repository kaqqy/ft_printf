/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 21:51:29 by jshi              #+#    #+#             */
/*   Updated: 2016/10/26 17:10:04 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			pound;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			apos;
	int			minwid;
	int			prec;
	int			lenmod;
	int			sign;
	uintmax_t	num;
	char		conv;
	va_list		arg_start;
}				t_flags;
int				ft_printf(const char *format, ...);
void			set_arg(char **pos, va_list *args, t_flags *f);
void			set_flags(char **pos, t_flags *f);
void			set_minwid(char **pos, va_list *args, t_flags *f);
void			set_prec(char **pos, va_list *args, t_flags *f);
void			set_lenmod(char **pos, t_flags *f);
char			*ft_itoa_base(uintmax_t n, int base);
void			prepend_char(char **str, char c, int min_len);
void			append_char(char **str, char c, int min_len);
void			prepend_str(char **dst, char *src);
void			append_str(char **dst, char *src);
void			insert_commas(char **str, int i);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
void			ft_putstr(char *str);
char			*ft_strsub(char *str, int start, int len);
void			ft_strtoupper(char *str);
void			ft_strrev(char *str);
char			*wchar_to_str(wchar_t c);
char			*get_signed_int(va_list *args, t_flags *f, int base);
char			*get_unsigned_int(va_list *args, t_flags *f, int base);
char			*get_float(long double a);
int				print_decimal(char *str, t_flags *f);
int				print_hex(char *str, t_flags *f, int fmt);
int				print_octal(char *str, t_flags *f);
int				print_string(va_list *args, t_flags *f);
int				print_char(va_list *args, t_flags *f);
int				print_not_flag(t_flags *f);
int				print_float(va_list *args, t_flags *f);
char			*round_float(char *str, int pos);
int				handle_nan(long double a, t_flags *f, int ret);
#endif
