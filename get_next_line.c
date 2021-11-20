/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:30:16 by wrolanda          #+#    #+#             */
/*   Updated: 2021/11/20 15:23:46 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	size_t	BUFFER_SIZE;
	ssize_t	check_read_byte;

	check_read_byte = 0;
	BUFFER_SIZE = 1;
	check_read_byte = read(fd, buf, BUFFER_SIZE);
	if (check_read_byte == 0)
		return (NULL);
}
/*ssize_t read(int fd, void *buf, size_t count);*/
