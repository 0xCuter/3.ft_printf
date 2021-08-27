/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:09:35 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:48:47 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	put_precision(char *str, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.dot >= 0)
	{
		ret += treat_width(flags.dot, ft_strlen(str), 0);
		ret += put_str(str, flags.dot);
	}
	else
		ret += put_str(str, ft_strlen(str));
	return (ret);
}

int	treat_string(char *str, t_flags flags)
{
	int	ret;

	ret = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		ret += put_precision(str, flags);
	if (flags.dot >= 0)
		ret += treat_width(flags.width, flags.dot, 0);
	else
		ret += treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		ret += put_precision(str, flags);
	return (ret);
}
