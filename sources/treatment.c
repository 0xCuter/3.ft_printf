/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:56:25 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:50:04 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	is_flag(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	treatment(int c, t_flags flags, va_list args)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = treat_char(va_arg(args, int), flags);
	else if (c == 's')
		ret = treat_string(va_arg(args, char *), flags);
	else if (c == 'p')
		ret = treat_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		ret = treat_int(va_arg(args, int), flags);
	else if (c == 'u')
		ret += treat_uint((unsigned int)va_arg(args, unsigned int), flags);
	else if (c == 'x')
		ret += treat_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		ret += treat_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		ret += treat_percent(flags);
	return (ret);
}
