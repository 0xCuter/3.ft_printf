/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:14:29 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:47:39 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	put_num(char *str, int num, t_flags flags)
{
	int	ret;

	ret = 0;
	if (num < 0 && flags.dot >= 0)
		put_char('-');
	if (flags.dot >= 0)
		ret += treat_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	ret += put_str(str, ft_strlen(str));
	return (ret);
}

static int	put_int(char *str, int num, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
		ret += put_num(str, num, flags);
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
		ret += put_num(str, num, flags);
	free(str);
	return (ret);
}

int	treat_int(int num, t_flags flags)
{
	int		tmp;
	int		ret;

	ret = 0;
	tmp = num;
	if (flags.dot == 0 && tmp == 0)
	{
		ret += treat_width(flags.width, 0, 0);
		return (ret);
	}
	if (tmp < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.dot == -1 && flags.zero == 1)
			put_str("-", 1);
		tmp *= -1;
		flags.zero = 1;
		flags.width--;
		ret++;
	}
	ret += put_int(ft_itoa(tmp), num, flags);
	return (ret);
}
