/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:25:03 by athirion          #+#    #+#             */
/*   Updated: 2022/08/02 17:37:35 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo_void)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) philo_void;
	data = philo->data;
	if ((philo->philo_id + 1) % 2 == 0)
		ft_check_time(data->time_to_eat, data);
	while (1)
	{
		pthread_mutex_lock(&(data->death));
		if (data->dead)
		{
			pthread_mutex_unlock(&(data->death));
			return (NULL);
		}
		pthread_mutex_unlock(&(data->death));
		ft_eat(data, philo);
		if (!ft_starving_philo(data, philo) || data->nb_philo == 1)
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
		pthread_mutex_lock(&(data->eat));
		philo[i].last_eating_time = ft_gettime();
		pthread_mutex_unlock(&(data->eat));
		i += 1;
	}
	return (0);
}

void	ft_dead_philo(t_data *data, t_philo *philo, int i)
{
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
				pthread_mutex_lock(&(data->death));
				data->dead = 1;
				pthread_mutex_unlock(&(data->death));
			}
			pthread_mutex_unlock(&(data->eat));
			i ++;
		}
		if (data->dead)
			return ;
		if (data->nb_of_meal != -1
			&& ft_eat_enough(data, philo) == data->nb_philo)
			break ;
	}
}

int	ft_philo(t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
	{
		free(data->fork);
		return (ft_error_message(8));
	}
	ft_init_philo(data, philo);
	data->start_time = ft_gettime();
	if (ft_launch_routine(data, philo))
	{
		free(data->fork);
		free(philo);
		return (1);
	}
	ft_dead_philo(data, philo, 0);
	ft_exit_philo(data, philo);
	free(data->fork);
	free(philo);
	return (0);
}
