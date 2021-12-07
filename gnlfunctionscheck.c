#include <stdio.h>
#include "get_next_line.h"
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
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
	res = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (res == NULL)
		return (NULL);
	res[ft_strlen(buf) - i + 1] = '\0';
	while (buf[i])
	{
		res[i2++] = buf[i++];
	}
	return (res);
}

int	main(void)
{
	char	buf[] = \
	"12345\n67890";
	char	*str2;
	int	k = ft_bufncheck(buf);
	printf("%d;\n", k);
	if (k > 0)
	{
		str2 = ft_bufsave(buf);
	}
	printf("(%s)\n", str2);
}
