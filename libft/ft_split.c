/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzumaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:15:18 by suzumaki          #+#    #+#             */
/*   Updated: 2020/11/06 18:21:36 by suzumaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_wrdcnt(char const *s, const char c)
{
	int words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s++ != c)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static int	ft_putwords(char const *s, char c, int words, char **split)
{
	char const	*start;
	int			w;
	size_t		letters;

	w = 0;
	while (words--)
	{
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		letters = s - start;
		split[w] = (char *)malloc(letters + 1);
		if (!split[w])
			return (w);
		(void)ft_strlcpy(split[w++], start, letters + 1);
	}
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		words;
	int		error;
	char	**split;

	if (!s)
		return (NULL);
	words = ft_wrdcnt(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	error = ft_putwords(s, c, words, split);
	if (!error)
		return (split);
	while (error--)
		free(split[error]);
	free(split);
	return (NULL);
}
