/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:43:35 by scuter            #+#    #+#             */
/*   Updated: 2021/01/27 11:21:27 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			i++;
			while (*str && *str != c)
				str++;
		}
		if (*str)
			str++;
	}
	return (i);
}

static void	ft_strcpy(char *dest, const char *first, const char *last)
{
	while (first < last)
	{
		*dest = *first;
		dest++;
		first++;
	}
	*dest = 0;
}

static char	**freee(char **tab, int i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	char	*first;

	words = malloc(sizeof(char*) * (word_count(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			first = (char *)s;
			while ((*s != c) && *s)
				s++;
			if (!(words[i] = malloc(sizeof(char) * (s - first + 1))))
				return (freee(words, i));
			ft_strcpy(words[i], first, s);
			i++;
		}
		if (*s)
			s++;
	}
	words[i] = NULL;
	return (words);
}
