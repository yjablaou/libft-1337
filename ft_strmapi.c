#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*ptr

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (!(ptr = (char *)malloc(l + 1)))
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}