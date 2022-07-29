#include "philo.h"

long long ft_gettime(void)
{
	struct timeval	time_value;
	long long		time;

	gettimeofday(&time_value, NULL);
	time = time_value.tv_sec * 1000 + time_value.tv_usec / 1000;
	return (time);
}


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

long	ft_atoi(const char *str)
{
	int			i;
	long		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = nb * 10 + str[i] - 48;
		i ++;
	}
	return (nb);
}
