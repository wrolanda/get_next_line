/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:25 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/14 15:45:56 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESCRIPTION
**	function which returns a line read from a file descriptor.
**	PARAMETERS
**	#1. A file descriptor 
**	RETURN VALUE
**	Read line: correct behavior
**	If successful, get_next_line returns a string with the full line ending in
**	a line break (`\n`) when there is one. 
**	NULL: nothing else to read or an error occurred
*/
#include "get_next_line.h"

char	*ft_saves_read(int fd, char *st_line)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(st_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		st_line = ft_strjoin(st_line, buff);
	}
	free(buff);
	return (st_line);
}

char	*ft_get_line(char *st_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!st_line[i])
		return (NULL);
	while (st_line[i] && st_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (st_line[i] && st_line[i] != '\n')
	{
		str[i] = st_line[i];
		i++;
	}
	if (st_line[i] == '\n')
	{
		str[i] = st_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rest_st_line(char *st_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (st_line[i] && st_line[i] != '\n')
		i++;
	if (!st_line[i])
	{
		free (st_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(st_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (st_line[i])
		str[j++] = st_line[i++];
	str[j] = '\0';
	free(st_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*res_line;
	static char	*st_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX - 1)
		return (0);
	st_line = ft_saves_read(fd, st_line);
	if (!st_line)
		return (NULL);
	res_line = ft_get_line(st_line);
	st_line = ft_rest_st_line(st_line);
	return (res_line);
}

/*#include <stdio.h>
int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("check.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
}*/
