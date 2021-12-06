/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:25 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/06 15:43:03 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*static = NULL*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res_line;
	static char	*buf;
	ssize_t		ret;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX - 1)
		return (0);
	res_line = (char *)malloc(sizeof(char) * 1);
	if (res_line == NULL)
		return (NULL);
	res_line[0] = '\0';
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	ret = read(fd, buf, BUFFER_SIZE);
	//if (ret > 0 && !res_line != ft_strchr(res_line, '\n')
	temp = res_line;
	res_line = ft_strjoin(res_line, buf);
	free(temp);
	return (res_line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("check.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
