/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:24:28 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:47:49 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	treat_percent(t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
		ret += put_str("%", 1);
	ret += treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ret += put_str("%", 1);
	return (ret);
}
