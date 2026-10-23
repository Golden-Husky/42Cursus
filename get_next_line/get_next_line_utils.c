#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	copy = malloc(len +1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while(i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
