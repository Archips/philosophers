/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:30:25 by athirion          #+#    #+#             */
/*   Updated: 2022/07/31 11:59:21 by athirion         ###   ########.fr       */
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
	while (!data->dead)
	{
		delta = ft_gettime() - time;
		if (delta >= time_to)
			return ;
		usleep(300);
	}
}
