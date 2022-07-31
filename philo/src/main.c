/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:29:49 by athirion          #+#    #+#             */
/*   Updated: 2022/07/31 09:29:50 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	error = ft_check_args(ac, av);
	if (error)
		return (ft_error_message(error));
	ft_init_data(&data, ac, av);
	if (ft_init_mutex(&data))
		return (1);
	if (ft_philo(&data))
		return (1);
	return (0);
}
