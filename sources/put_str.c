/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:19:03 by scuter            #+#    #+#             */
/*   Updated: 2021/06/14 10:32:22 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		put_str(char *str, int precision)
{
	int ret;

	ret = 0;
	while (str[ret] && ret < precision)
	{
		put_char(str[ret]);
		ret++;
	}
	return (ret);
}
