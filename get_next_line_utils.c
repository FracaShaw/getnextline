/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:23:58 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/05 16:41:27 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*s3;
	t_int	iter;

	iter.r = 0;
	iter.i = 0;
	if (!s1)
		iter.check = 0;
	else
		iter.check = ft_strlen(s1);
	s3 = malloc(iter.check + n + 1);
	if (!s3)
		return (NULL);
	while (iter.r < iter.check)
	{
		s3[iter.r] = s1[iter.r];
		iter.r++;
	}
	while (s2[iter.i] && iter.i < n)
	{
		s3[iter.r] = s2[iter.i];
		iter.i++;
		iter.r++;
	}
	s3[iter.r] = '\0';
	return (s3);
}

unsigned long int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (NULL);
	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
