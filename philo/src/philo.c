/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:25:03 by athirion          #+#    #+#             */
/*   Updated: 2022/07/31 09:25:07 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo_void)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) philo_void;
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
		if (pthread_create(&(philo[i].philo_thread),
				NULL, ft_routine, &(philo[i])) != 0)
			return (ft_error_message(7));
		philo[i].last_eating_time = ft_gettime();
		i += 2;
	}
	i = 1;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].philo_thread),
				NULL, ft_routine, &(philo[i])) != 0)
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
			break ;
		i = ft_eat_enough(data, philo);
		if (data->nb_of_meal != -1 && i == data->nb_philo)
			data->eat_enough = 1;
	}
}

int	ft_philo(t_data *data)
{
	t_philo	*philo;

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
