#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_1 "Wrong number of arguments\n"
# define ERR_2 "Wrong format of arguments\n"
# define ERR_3 "Arguments has to be inferior or equal to INT MAX\n"
# define ERR_4 "Number of philosophers has to be min 1\n"
# define ERR_5 "Number of times each philosopher must eat has to be min 1\n" 

typedef struct	s_philo
{
	pthread_t	philo_thread;

	int			l_fork;
	int			r_fork;
	int			meal_eaten;
	int			philo_id

}				t_philo;

typedef struct	t_data
{

	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_of_meal;

	t_philo		philo[nb_philo];

}				t_data;

/*
 ** [   ERROR.C   ]
 */

int	ft_is_num(int ac, char **av);
int	ft_check_args(int ac, char **av);	
int	ft_error_message(int err);

/*
 ** [   UTILS.C   ]
 */

int		ft_strlen(const char *str);
long	ft_atoi(const char *str);

/*
 ** [   INIT.C   ]
 */

void	ft_init_data(t_data *data, int ac, char **av);
void	ft_init_philo(t_data *data);

/*
 ** [   MAIN.C   ]
 */

int		main(int ac, char **av);

#endif
