/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:54:56 by scuter            #+#    #+#             */
/*   Updated: 2021/07/09 20:22:36 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		init_flags(void)
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

int		flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !is_type(save[i]) && !is_flag(save[i]))
			break;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = flag_dot(save, i + 1, flags, args);
		if (save[i] == '-')
			*flags = flag_minus(*flags);
		if (save[i] == '*')
			*flags = flag_width(args, *flags);
		if (ft_isdigit(save[i]))
			*flags = flag_digit(save[i], *flags);
		if (is_type(save[i]))
		{
			flags->type = save[i];
			break;
		}
		i++;
	}
	return (i);
}

int		format_parse(const char *save, va_list args)
{
	t_flags		flags;
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (1)
	{
		flags = init_flags();
		if (!save[i])
			break;
		else if (save[i] == '%' && save[i + 1])
		{
			i = flag_parse(save, ++i, &flags, args);
			if (is_type(save[i]))
				ret += treatment((char)flags.type, flags, args);
			else if (save[i])
				ret += put_char(save[i]);
		}
		else if (save[i] != '%')
			ret += put_char(save[i]);
		i++;
	}
	return (ret);
}

int		ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		args;
	int			ret;

	ret = 0;
	save = ft_strdup(input);
	va_start(args, input);
	ret += format_parse(save, args);
	va_end(args);
	free((char *)save);
	return (ret);
}
