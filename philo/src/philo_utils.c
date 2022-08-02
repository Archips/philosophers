/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:30:25 by athirion          #+#    #+#             */
/*   Updated: 2022/08/02 15:34:34 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&(data->log));
	if (!data->dead)
		printf("%lld %d %s\n", ft_gettime() - data->start_time, id + 1, action);
	pthread_mutex_unlock(&(data->log));
}

void	ft_check_time(int time_to, t_data *data)
{
	long long	time;
	long long	delta;

	time = ft_gettime();
	while (1)
	{
		pthread_mutex_lock(&(data->eat));
		if (data->dead)
		{
			pthread_mutex_unlock(&(data->eat));
			break ;
		}
		pthread_mutex_unlock(&(data->eat));
		delta = ft_gettime() - time;
		if (delta >= time_to)
			break ;
		usleep(30);
	}
}
