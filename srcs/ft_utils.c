
#include "so_long.h"

static int	ft_nblen(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	long	nb;

	nb = n;
	len = ft_nblen(n);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (nb == 0)
		ret[0] = '0';
	while (nb > 0)
	{
		ret[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ret);
}

int	ft_key_count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}
