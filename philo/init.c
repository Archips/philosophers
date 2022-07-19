#include "philo.h"

void	ft_init_data(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_meal = ft_atoi(av[5]);
	else
		data->nb_of_meal = -1;
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].r_fork = i;
		if (i == 0)
			data->philo[i].l_fork = data->nb_philo - 1;
		else
			data->philo[i].l_fork = i - 1;
		data->philo[i].philo_id = i;
		data->philo[i].meal_eaten = 0;
		i ++;
	}
}
