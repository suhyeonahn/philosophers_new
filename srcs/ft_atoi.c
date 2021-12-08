#include "../includes/philo.h"

int	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size])
	{
		size++;
	}
	return (size);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	if (ft_strlen(str) > 11 || !str[i])
        return (-1);    
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
            return (-1);
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num < INT_MIN || num > INT_MAX)
        return (-1);
	return (num);
}