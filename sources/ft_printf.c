/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:54:56 by scuter            #+#    #+#             */
/*   Updated: 2021/08/26 17:42:05 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	flag_parse(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_type(str[i]) && !is_flag(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = flag_dot(str, i + 1, flags, args);
		if (str[i] == '-')
			*flags = flag_minus(*flags);
		if (str[i] == '*')
			*flags = flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = flag_digit(str[i], *flags);
		if (is_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	format_parse(const char *str, va_list args)
{
	t_flags		flags;
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			flags = init_flags();
			i = flag_parse(str, ++i, &flags, args);
			if (is_type(str[i]))
				ret += treatment((char)flags.type, flags, args);
			else if (str[i])
				ret += put_char(str[i]);
		}
		else if (str[i] != '%')
			ret += put_char(str[i]);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			ret;

	ret = 0;
	va_start(args, input);
	ret += format_parse(input, args);
	va_end(args);
	return (ret);
}
