/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:48:53 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/05 17:15:32 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

unsigned int	leftover_check(char *leftover, char **file)
{
	long long int	i;
	unsigned int	check;

	check = 0;
	i = 0;
	while (leftover[i])
	{
		if (leftover[i] == '\n')
			check = 1;
		i++;
	}
	if (!check)
	{
		*file = ft_strdup(leftover);
		leftover[0] = '\0';
	}
	return (check);
}

int	read_if_check(t_int *s, char *buf, char *leftover, int fd)
{
	if (!s->check)
	{
		s->r = read(fd, buf, BUFFER_SIZE);
		buf[s->r] = '\0';
	}
	else
	{
		ft_strcpy(buf, leftover);
		s->r = 0;
	}
	return (s->r);
}

char	*new_line_extraction(char *file, t_int s, char *leftover, char *buf)
{
	char	*temp;

	temp = file;
	file = ft_strnjoin(file, buf, s.i + 1);
	if (temp)
		free (temp);
	if (buf[s.i] == '\n')
		ft_strcpy(leftover, buf + s.i + 1);
	if (buf[s.i] == '\0' && s.r == 0)
	{
		if (file[0] == '\0')
		{
			free (file);
			file = NULL;
		}
	}
	return (file);
}

char	*get_next_line(int fd)
{
	char				buf[BUFFER_SIZE + 1];
	static char			leftover[BUFFER_SIZE + 1];
	char				*file;
	t_int				s;

	file = NULL;
	s.check = leftover_check(leftover, &file);
	while (1)
	{
		s.i = 0;
		if (read_if_check(&s, buf, leftover, fd) == -1)
			return (NULL);
		while (buf[s.i] != '\n' && buf[s.i])
			s.i++;
		if (buf[s.i] == '\n')
			return (new_line_extraction(file, s, leftover, buf));
		if (!buf[s.i])
		{
			file = new_line_extraction(file, s, leftover, buf);
			if (s.r == 0)
			{
				return (file);
			}
		}
	}
}
/*
int main()
{
	int fd;

	fd = open("test", O_RDONLY);
	printf("--------------- test 1 ----------------");
	printf("fd1:%d\n", fd);
	printf("test1\n");
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));

	fd = open("test2", O_RDONLY);
	printf("--------------- test 2 ----------------");
	printf("fd2:%d\n", fd);
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));

	fd = open("test_empty", O_RDONLY);
	printf("--------------- test 3 ----------------");
	printf("fd3:%d\n", fd);
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));

	fd = open("test_nl", O_RDONLY);
	printf("--------------- test 4 ----------------");
	printf("fd4:%d\n", fd);
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));

	fd = open("test_5nl", O_RDONLY);
	printf("--------------- test 5 ----------------");
	printf("fd5:%d\n", fd);
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));
	printf("new_line:%s\n", get_next_line(fd));


}
*/
