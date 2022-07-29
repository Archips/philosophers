#include "philo.h"

int	ft_eat_enough(t_data *data, t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&(data->eat));
		if (data->nb_of_meal != philo[i].meal_eaten)
			return (i);
		pthread_mutex_unlock(&(data->eat));
		i ++;
	}
	return (i);
}

void	ft_log(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&(data->log));
	printf("%lld %d %s\n", ft_gettime() - data->start_time, id + 1, action);
	pthread_mutex_unlock(&(data->log));
}

void	ft_check_time(int time_to, t_data *data)
{
	long long	time;
	long long	delta;

	time = ft_gettime();
	while (!data->dead)
	{
		delta = ft_gettime() - time;
		if (delta >= time_to)
			return ;
		usleep(50);
	}
}

void	ft_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->fork[philo->r_fork]));
	ft_log(data, philo->philo_id, FORK);
	pthread_mutex_lock(&(data->fork[philo->l_fork]));
	ft_log(data, philo->philo_id, FORK);
	pthread_mutex_lock(&(data->eat));
	ft_log(data, philo->philo_id, EAT);
	philo->last_eating_time = ft_gettime();
	pthread_mutex_unlock(&(data->eat));
	ft_check_time(data->time_to_eat, data);
	philo->meal_eaten += 1;
	pthread_mutex_unlock(&(data->fork[philo->l_fork]));
	pthread_mutex_unlock(&(data->fork[philo->r_fork]));
}	

void	*ft_routine(void *philo_void)
{
	t_philo	*philo;
	t_data	*data;

	philo = philo_void;
	data = philo->data;
	while (!data->dead)
	{
		ft_eat(data, philo);
		if (data->nb_of_meal != -1 && data->eat_enough)
			return (NULL);
		ft_log(data, philo->philo_id, SLEEP);
		ft_check_time(data->time_to_sleep, data);
		ft_log(data, philo->philo_id, THINK);
	}
	return (NULL);
}

int	ft_launch_routine(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].philo_thread), NULL, ft_routine, &(philo[i])) != 0)
			return (ft_error_message(7));
		philo[i].last_eating_time = ft_gettime();
		i += 2;
	}
	i = 1;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].philo_thread), NULL, ft_routine, &(philo[i])) != 0)
			return (ft_error_message(7));
		philo[i].last_eating_time = ft_gettime();
		i += 2;
	}
	return (0);
}

void	ft_dead_philo(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo && !data->dead)
		{
			pthread_mutex_lock(&(data->eat));
			data->death_time = ft_gettime() - philo[i].last_eating_time;
			if (data->death_time > data->time_to_die)
			{
				ft_log(data, philo[i].philo_id, DEATH);
				data->dead = 1;
			}
			pthread_mutex_unlock(&(data->eat));
			i ++;
		}
		if (data->dead)
			break;
		i = ft_eat_enough(data, philo);
		if (data->nb_of_meal != -1 && i == data->nb_philo)
			data->eat_enough = 1;
	}
}

int	ft_philo(t_data *data)
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (ft_error_message(8));
	ft_init_philo(data, philo);
	data->start_time = ft_gettime();
	if (ft_launch_routine(data, philo))
		return (1);	
	ft_dead_philo(data, philo);
	ft_exit_philo(data, philo);
	return (0);
}
