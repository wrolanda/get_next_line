/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:31:16 by wrolanda          #+#    #+#             */
/*   Updated: 2021/11/25 19:05:10 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*for read*/
# include <unistd.h>

/*for open and fd*/
# include <fcntl.h>

/*for malloc*/
# include <stdlib.h>
char	*get_next_line(int fd);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);

#endif