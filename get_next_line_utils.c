/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda < wrolanda@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:31:01 by wrolanda          #+#    #+#             */
/*   Updated: 2021/12/13 16:16:06 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*memset - fill a byte string with a byte value
DESCRIPTION
	The memset() function writes len bytes of value c (converted to an
	unsigned char) to the string b.*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
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
	void	*p;

	p = (void *)malloc(size * count);
	if (p == (void *)0)
		return ((void *)0);
	ft_bzero(p, count * size);
	return (p);
}

/*strlcpy, strlcat -- size-bounded string copying and concatenation
DESCRIPTION
	strlcat() appends string src to the end of dst.  It will append at most
	dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
	dstsize is 0 or the original dst string was longer than dstsize (in prac-
	tice this should not happen as it means that either dstsize is incorrect
	or that dst is not a proper string).*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res_dst;
	size_t	res_src;

	i = 0;
	res_dst = ft_strlen(dst);
	res_src = ft_strlen((char *)src);
	j = res_dst;
	if (dstsize <= 0)
		return (res_src + dstsize);
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (dstsize != 0 && res_dst <= dstsize)
		dst[j] = '\0';
	if (dstsize < res_dst)
		return (res_src + dstsize);
	else
		return (res_dst + res_src);
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
	char	*newstr;
	size_t	i;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = ft_calloc(sizeof(char), i + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strlcat(newstr, s1, i + 1);
	ft_strlcat(newstr, s2, i + 1);
	return (newstr);
}

/*strchr, strrchr -- locate character in string
DESCRIPTION
	The strchr() function locates the first occurrence of c (converted to a
	char) in the string pointed to by s.  The terminating null character is
	considered to be part of the string; therefore if c is `\0', the func-
	tions locate the terminating `\0'.*/

char	*ft_strchr(const char *s, int c)
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
