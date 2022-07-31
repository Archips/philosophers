/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:28:34 by athirion          #+#    #+#             */
/*   Updated: 2022/07/31 09:28:35 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	(void) ac;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	int		i;
	long	nb;

	i = 1;
	if (ac != 5 && ac != 6)
		return (1);
	if (!ft_is_num(ac, av))
		return (2);
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (3);
		i ++;
	}
	if (ft_atoi(av[1]) < 1)
		return (4);
	if (ac == 6 && ft_atoi(av[5]) < 1)
		return (5);
	return (0);
}

int	ft_error_message(int err)
{
	if (err == 1)
		write(2, ERR_1, ft_strlen(ERR_1));
	if (err == 2)
		write(2, ERR_2, ft_strlen(ERR_2));
	if (err == 3)
		write(2, ERR_3, ft_strlen(ERR_3));
	if (err == 4)
		write(2, ERR_4, ft_strlen(ERR_4));
	if (err == 5)
		write(2, ERR_5, ft_strlen(ERR_5));
	if (err == 6)
		write(2, ERR_6, ft_strlen(ERR_6));
	if (err == 7)
		write(2, ERR_7, ft_strlen(ERR_7));
	if (err == 8)
		write(2, ERR_8, ft_strlen(ERR_8));
	return (1);
}
