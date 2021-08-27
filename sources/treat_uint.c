/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:17:14 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:49:08 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	write_uint(char *str, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.dot >= 0)
		ret += treat_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	ret += put_str(str, ft_strlen(str));
	return (ret);
}

static int	put_uint(char *str, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
		ret += write_uint(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ret += treat_width(flags.width, 0, 0);
	}
	else
		ret += treat_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		ret += write_uint(str, flags);
	free(str);
	return (ret);
}

int	treat_uint(unsigned int ui, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.dot == 0 && ui == 0)
	{
		ret += treat_width(flags.width, 0, 0);
		return (ret);
	}
	ret += put_uint(uitoa(ui), flags);
	return (ret);
}
