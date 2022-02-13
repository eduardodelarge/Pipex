/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:26:29 by caeduard          #+#    #+#             */
/*   Updated: 2022/02/13 18:41:38 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strsep (char **stringp, const char *delim)
{
  char *begin;
  char *end;
  
  begin = *stringp;
  if (begin == NULL)
    return NULL;
  end = begin + strcspn (begin, delim);
  if (*end)
    {
      *end++ = '\0';
      *stringp = end;
    }
  else
    *stringp = NULL;
  return begin;
}