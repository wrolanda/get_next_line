/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:30:16 by wrolanda          #+#    #+#             */
/*   Updated: 2021/11/25 19:09:28 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	//size_t	BUFFER_SIZE;
	size_t	num_byte_read;

	line = (char *)malloc(sizeof(char) * 1000);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	num_byte_read = 0;
	//BUFFER_SIZE = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	num_byte_read = read(fd, buf, BUFFER_SIZE); //read возвращает кол-во считанных байт
	if (num_byte_read == 0)
		return (NULL);
	num_byte_read = ft_strlcpy(line, buf, BUFFER_SIZE + 1);
	return (line);
}
/*ssize_t read(int fd, void *buf, size_t count);*/

#include <stdio.h>
int	main(void)
{
	char	name[] = "check.txt";
	int		fd;
	char	*str;

	fd = open(name, O_RDONLY);
	str = get_next_line(fd);
	printf("(%s)", str);
	//or
	//write (fd, str, ft_strlen(str));
}

