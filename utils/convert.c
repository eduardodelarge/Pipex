/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:03:36 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/17 11:26:18 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*convert(char *string, char spc, char ascii)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(string);
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
			{
				if (str[i] == spc)
					str[i] = ascii;
				i++;
			}
		}
		i++;
	}
	return (str);
}

int	check_char(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == 1)
			return (1);
		len++;
	}
	return (0);
}

void	reverse(char **matrix)
{
	int		i;
	char	*tmp;
	char	*temp;

	i = 0;
	while (matrix[i])
	{
		if (check_char(matrix[i]))
		{
			tmp = convert(matrix[i], 1, ' ');
			temp = ft_strtrim(tmp, "'");
			free(matrix[i]);
			matrix[i] = ft_strdup(temp);
			free(tmp);
			free(temp);
		}
		i++;
	}
}