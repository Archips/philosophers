/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:28:23 by athirion          #+#    #+#             */
/*   Updated: 2022/07/31 09:39:03 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pthread_mutex_lock(&(data->eat));
	philo->meal_eaten += 1;
	pthread_mutex_unlock(&(data->eat));
	pthread_mutex_unlock(&(data->fork[philo->r_fork]));
	pthread_mutex_unlock(&(data->fork[philo->l_fork]));
}	
