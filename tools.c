#include <stdlib.h>
#include "rstr.h"
int ft_pow(double base, double power)
{
	int i;
	double p;

	i = 0;
	p = 1;
	while (i < power)
	{
		p *= base;
		i++;	
	}
	return (p);
}

void		*ft_mem_grow(void *addr, size_t old_size, size_t new_size)
{
	void *tmp;

	tmp = malloc(new_size);
	ft_memcpy(tmp, addr, old_size);
	free(addr);
	return (tmp);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tdst;
	const char	*tsrc;

	tdst = dst;
	tsrc = src;
	if (dst == src && n == 1)
		return (dst);
	if (!tsrc && !tdst)
		return (0);
	while (n > 0)
	{
		*tdst++ = *tsrc++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		strstr_modified(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	m;
	char	*pt;

	pt = (char *)haystack;
	i = 0;
	j = 0;
	n = ft_strlen(haystack);
	m = ft_strlen(needle);
	while (i <= (n - m))
	{
		j = 0;
		while (j < m)
		{
			if (needle[j] != haystack[i + j])
				break ;
			j++;
		}
		if (j == m)
			return (i);
		i++;
	}
	return (-1);
}