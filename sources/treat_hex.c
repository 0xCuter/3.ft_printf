/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:19:41 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:47:23 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	write_hex(char *hex, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.dot >= 0)
		ret += treat_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	ret += put_str(hex, ft_strlen(hex));
	return (ret);
}

static int	put_hex(char *hex, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
		ret += write_hex(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ret += treat_width(flags.width, 0, 0);
	}
	else
		ret += treat_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		ret += write_hex(hex, flags);
	return (ret);
}

int	treat_hex(unsigned int ui, int lower, t_flags flags)
{
	char	*hex;
	int		ret;

	ret = 0;
	if (flags.dot == 0 && ui == 0)
	{
		ret += treat_width(flags.width, 0, 0);
		return (ret);
	}
	hex = save_base((unsigned long long)ui, 16);
	if (lower == 1)
		hex = str_tolower(hex);
	ret += put_hex(hex, flags);
	free(hex);
	return (ret);
}
