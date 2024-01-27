/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:31:02 by coder             #+#    #+#             */
/*   Updated: 2022/02/17 15:31:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	character;

	index = 0;
	character = (char)c;
	while (s[index] != '\0')
	{
		if (s[index] == character)
			return ((char *)s + index);
		index++;
	}
	if (character == '\0')
		return ((char *)s + index);
	return (0);
}

static size_t	frst_char(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	last_char(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (i + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*strnew;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = frst_char(s1, set);
	end = last_char(&s1[start], set);
	strnew = ft_substr(s1, start, end);
	return (strnew);
}
