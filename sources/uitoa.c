/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:15:33 by scuter            #+#    #+#             */
/*   Updated: 2021/08/24 14:50:48 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	digits(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*uitoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = digits(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	while (len)
	{
		str[len - 1] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}
