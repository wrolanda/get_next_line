/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:25 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/07 19:03:37 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*static = NULL*/
#include "get_next_line.h"
#include <stdio.h>

/*char	*ft_bufcut(char *buf)
{
	
}
int	ft_bufncheck(char *buf)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			l++;
		i++;
	}
	return (l);
}

char	*ft_bufsave(char *buf)
{
	char	*res;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (NULL);
	i++;
	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	res[BUFFER_SIZE - i + 1] = '\0';
	while (buf[i])
	{
		res[i2++] = buf[i++];
	}
	free (buf);
	return (res);
}*/

char	*get_next_line(int fd)
{
	static char	*res_line;
	static char	*buf;
	ssize_t		ret;
	char		*temp;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX - 1)
		return (0);
	res_line = (char *)malloc(sizeof(char) * 1);
	if (res_line == NULL)
		return (NULL);
	res_line[0] = '\0';
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	//buf = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buf == NULL)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		temp = res_line;
		res_line = ft_strjoin(temp, buf);
		ft_bzero(buf, BUFFER_SIZE);
		free(temp);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (res_line[0] == '\0')
	{
		free(buf);
		return (NULL);
	}
	//while (ret > 0 && buf != ft_strchr(buf, '\n'))
	free (buf);
	return (res_line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("check.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}
