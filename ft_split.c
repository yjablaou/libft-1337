/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:51:21 by yojablao          #+#    #+#             */
/*   Updated: 2023/11/19 14:17:43 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_words(const char *s, char c)
{
	size_t	word_count;
	size_t	i;
	size_t	len;

	i = 0;
	word_count = 0;
	len = ft_strlen(s);
	while (s[i] == c)
		i++;
	while (i < len)
	{
		if (s[i] != c)
		{
			word_count++;
			while (i < len && s[i] != c)
				i++;
		}
		else
		{
			while (i < len && s[i] == c)
				i++;
		}
	}
	return (word_count);
}

ssize_t	norm(char const *s, char c, char **str, size_t i)
{
	size_t	start;
	size_t	l;

	l = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[l++] = ft_substr(s, start, i - start);
			if (str[l - 1] == NULL)
			{
				while (--l >= 0)
					free(str[l]);
				return (-1);
			}
		}
		else
			i++;
	}
	return (l);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	ssize_t	l;
	size_t	i;
	size_t	word_count;

	if (s[0] == '\0')
	{
		str = malloc(sizeof(char *));
		str[0] = NULL;
		return (str);
	}
	word_count = count_words (s, c);
	str = (char **)ft_calloc((word_count + 1) * sizeof(char *), 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	l = norm(s, c, str, i);
	if (l == -1) 
	{
		free (str);
		return (NULL);
	}
	str[l] = NULL;
	return (str);
}
