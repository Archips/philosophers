/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:29:03 by athirion          #+#    #+#             */
/*   Updated: 2022/08/01 16:09:43 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->dead = 0;
	data->eat_enough = 0;
	data->start_time = 0;
	if (ac == 6)
		data->nb_of_meal = ft_atoi(av[5]);
	else
		data->nb_of_meal = -1;
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (ft_error_message(8));
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL) != 0)
			return (ft_error_message(6));
		i ++;
	}
	if (pthread_mutex_init(&(data->eat), NULL) != 0)
		return (ft_error_message(6));
	if (pthread_mutex_init(&(data->death), NULL) != 0)
		return (ft_error_message(6));
	if (pthread_mutex_init(&(data->log), NULL) != 0)
		return (ft_error_message(6));
	return (0);
}

void	ft_init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].data = data;
		philo[i].last_eating_time = 0;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % data->nb_philo;
		philo[i].philo_id = i;
		philo[i].meal_eaten = 0;
		i ++;
	}
}
