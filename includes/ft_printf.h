/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:18:36 by scuter            #+#    #+#             */
/*   Updated: 2021/08/26 18:09:52 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}	t_flags;

int			ft_printf(const char *input, ...);
int			is_type(int c);
int			is_flag(int c);
int			treatment(int c, t_flags flags, va_list args);
t_flags		flag_minus(t_flags flags);
t_flags		flag_digit(char c, t_flags flags);
t_flags		flag_width(va_list args, t_flags flags);
int			flag_dot(const char *str, int i, t_flags *flags, va_list args);
int			treat_char(char c, t_flags flags);
int			treat_width(int width, int minus, int zero);
int			treat_string(char *str, t_flags flags);
int			put_str(char *str, int precision);
int			treat_pointer(unsigned long long ull, t_flags flags);
char		*save_base(unsigned long long ull, int base);
char		*str_tolower(char *str);
int			treat_int(int num, t_flags flags);
int			treat_uint(unsigned int ui, t_flags flags);
int			treat_hex(unsigned int ui, int lower, t_flags flags);
int			treat_percent(t_flags flags);
char		*uitoa(unsigned int n);
int			put_char(int c);

#endif
