/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:20:15 by scuter            #+#    #+#             */
/*   Updated: 2021/06/29 10:56:43 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		treat_char(char c, t_flags flags)
{
	int ret;

	ret = 0;
	if (flags.minus == 1)
		put_char(c);
	ret = treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		put_char(c);
	return (ret + 1);
}
