/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:28:04 by scuter            #+#    #+#             */
/*   Updated: 2021/06/29 10:56:43 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		treat_width(int width, int len, int zero)
{
	int ret;

	ret = 0;
	while (width - len > 0)
	{
		if (zero)
			put_char('0');
		else
			put_char(' ');
		width--;
		ret++;
	}
	return(ret);
}
