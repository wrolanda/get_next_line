/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:30:16 by wrolanda          #+#    #+#             */
/*   Updated: 2021/11/26 19:04:07 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*res_line;
	size_t		BUFFER_SIZE;
	size_t		num_byte_read;

	if (fd < 0 || !res_line || BUFFER_SIZE <= 0)
		return (-1);
	res_line = (char *)malloc(sizeof(char) * 1000);
	if (res_line == NULL)
		return (NULL);
	res_line[0] = '\0';
	BUFFER_SIZE = 3;
	//int	i = 0;
	while (num_byte_read > 0 && !(ft_strchr(line, '\n')))
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (buf == NULL)
			return (NULL);
		buf[BUFFER_SIZE] = '\0';
		num_byte_read = read(fd, buf, BUFFER_SIZE); //read возвращает кол-во считанных байт
		num_byte_read = ft_strlcat(res_line, buf, BUFFER_SIZE + 1);
		free (buf);
	}
	return (line);
}
/*ssize_t read(int fd, void *buf, size_t count);*/

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("check.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	//or
	//write (fd, str, ft_strlen(str));
}

