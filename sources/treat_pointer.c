/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:00:24 by scuter            #+#    #+#             */
/*   Updated: 2021/06/28 10:09:27 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	put_ptr(char *ptr, t_flags flags)
{
	int ret;

	ret = 0;
	ret += put_str("0x", 2);
	if (flags.dot >= 0)
	{
		ret += treat_width(flags.dot, ft_strlen(ptr), 1);
		ret += put_str(ptr, flags.dot);
	}
	else
		ret += put_str(ptr, ft_strlen(ptr));
	return (ret);
}

int			treat_pointer(unsigned long long ull, t_flags flags)
{
	char *ptr;
	int ret;

	ret = 0;
	if (ull == 0 && flags.dot == 0)
	{
		ret += put_str("0x", 2);
		return (ret += treat_width(flags.width, 0, 1));
	}
	ptr = save_base(ull, 16);
	ptr = str_tolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		ret += put_ptr(ptr, flags);
	ret += treat_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		ret += put_ptr(ptr, flags);
	free(ptr);
	return (ret);
}
