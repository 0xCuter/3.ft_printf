/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:00:20 by scuter            #+#    #+#             */
/*   Updated: 2021/07/09 20:22:36 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			flag_dot(const char *save, int i, t_flags *flags, va_list args)
{
	if (save[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[i]))
			flags->dot = (flags->dot * 10) + (save[i++] - '0');
	}
	return (i);
}
