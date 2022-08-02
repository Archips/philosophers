/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:28:23 by athirion          #+#    #+#             */
/*   Updated: 2022/08/02 17:35:11 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_starving_philo(t_data *data, t_philo *philo)
{
	if (data->nb_of_meal == philo->meal_eaten)
		return (0);
	return (1);
}

int	ft_eat_enough(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&(data->eat));
		if (data->nb_of_meal != philo[i].meal_eaten)
		{
			pthread_mutex_unlock(&(data->eat));
			return (i);
		}
		pthread_mutex_unlock(&(data->eat));
		i ++;
	}
	return (i);
}

void	ft_eat(t_data *data, t_philo *philo)
{
	if (philo->r_fork < philo->l_fork)
		ft_swap(&(philo->r_fork), &(philo->l_fork));
	pthread_mutex_lock(&(data->fork[philo->r_fork]));
	ft_log(data, philo->philo_id, FORK);
	if (data->nb_philo == 1)
	{
		pthread_mutex_unlock(&(data->fork[philo->r_fork]));
		return ;
	}
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
	pthread_mutex_unlock(&(data->fork[philo->l_fork]));
	pthread_mutex_unlock(&(data->fork[philo->r_fork]));
}
