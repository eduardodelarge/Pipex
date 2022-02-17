/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:40:29 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/17 15:32:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *str)
{
	char	*string;
	size_t	index;

	index = 0;
	string = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!string)
		return (0);
	while (str[index])
	{
		string[index] = str[index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return (ft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_len_words(char const *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] != delimiter && str[i])
		i++;
	return (i);
}

static size_t	count_words(char const *str, char delimiter)
{
	size_t	i;
	size_t	aux;

	if (!*str)
		return (0);
	i = 1;
	aux = 0;
	while (str[i])
	{
		if (str[i] != delimiter && str[i])
		{
			aux++;
			while (str[i] != delimiter && str[i])
				i++;
		}
		else
			i++;
	}
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	size_t	n_chars;
	size_t	index;
	char	**string;

	if (!s)
		return (0);
	n_words = count_words(s, c);
	string = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!string)
		return (0);
	index = 0;
	while (index < n_words)
	{
		while (*s && *s == c)
			s++;
		n_chars = count_len_words(s, c);
		string[index] = ft_substr(s, 0, n_chars);
		s += n_chars + 1;
		index++;
	}
	string[index] = 0;
	return (string);
}
