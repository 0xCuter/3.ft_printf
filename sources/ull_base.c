/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:10:15 by scuter            #+#    #+#             */
/*   Updated: 2021/06/28 11:46:23 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*treat_base(unsigned long long ull, int base, char *ret, int i)
{
	while (ull != 0)
	{
		i--;
		if ((ull % base) < 10)
			ret[i] = (ull % base) + '0';
		else
			ret[i] = (ull % base) - 10 + 'A';
		ull /= base;
	}
	return (ret);
}

char			*save_base(unsigned long long ull, int base)
{
	char				*ret;
	unsigned long long	tmp;
	int					i;

	ret = 0;
	i = 0;
	tmp = ull;
	if (tmp == 0)
		return (ft_strdup("0"));
	while (tmp != 0)
	{
		tmp /= base;
		i++;
	}
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i] = 0;
	ret = treat_base(ull, base, ret, i);
	return (ret);
}
