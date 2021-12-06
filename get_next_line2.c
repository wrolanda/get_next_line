/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:25 by wrolanda          #+#    #+#             */
/*   Updated: 2021/11/26 19:37:43 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res_line; // = NULL
	char		*buf;
	size_t		BUFFER_SIZE;
	size_t		num_byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0 && BUFFER_SIZE >= max_int - 1)
		return (-1);
	res_line = (char *)malloc(sizeof(char) * 1);
	if // проверка на нулл
	res_line[0] = '\0';
	ret = read();
	ret > 0 && !res_line != ft_strchr (line)'\n');

}
