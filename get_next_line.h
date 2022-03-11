/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:16:44 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/05 16:36:23 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_int
{
	long long int	r;
	long long int	i;
	unsigned int	check;
}	t_int;

char				*get_next_line(int fd);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned long int	ft_strlen(const char *s);
char				*ft_strnjoin(char const *s1, char const *s2, int n);
char				*ft_strdup(const char *s1);
#endif
