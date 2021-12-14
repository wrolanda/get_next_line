/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:31:01 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/14 18:02:37 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*strchr, strrchr -- locate character in string
DESCRIPTION
	The strchr() function locates the first occurrence of c (converted to a
	char) in the string pointed to by s.  The terminating null character is
	considered to be part of the string; therefore if c is `\0', the func-
	tions locate the terminating `\0'.*/

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*calloc - memory allocation.
	The calloc() function contiguously allocates
	enough space for count objectsthat are size 
	bytes of memory each and returns a pointer to the 
	allocated memory.  The allocated memory is filled
	with bytes of value zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			i;
	unsigned char	*str;

	p = (void *)malloc(size * count);
	if (p == (void *)0)
		return ((void *)0);
	str = p;
	i = 0;
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return (p);
}

/*
DESCRIPTION
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.

PARAMETERS
#1. The prefix string.
#2. The suffix string.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(sizeof(char), i + 1);
	if (newstr == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			newstr[i] = s1[i];
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (newstr);
}
