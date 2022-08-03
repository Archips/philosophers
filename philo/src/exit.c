/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:28:42 by athirion          #+#    #+#             */
/*   Updated: 2022/08/03 18:19:38 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philo[i].philo_thread, NULL);
		i ++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&(data->fork[i]));
		i ++;
	}
	pthread_mutex_destroy(&(data->eat));
	pthread_mutex_destroy(&(data->death));
	pthread_mutex_destroy(&(data->log));
}
