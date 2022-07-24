#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_1	"Wrong number of arguments\n"
# define ERR_2	"Wrong format of arguments\n"
# define ERR_3	"Arguments has to be inferior or equal to INT MAX\n"
# define ERR_4	"Number of philosophers has to be min 1\n"
# define ERR_5	"Number of times each philosopher must eat has to be min 1\n" 
# define ERR_6	"Mutex error\n"
# define ERR_7	"Thread error\n"
# define ERR_8	"Malloc error\n"

# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define FORK	"has taken a fork"
# define DEATH	"died"

typedef struct	t_data
{

	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meal;
	int				dead;

	long long		start_time;
	long long		death_time;

	pthread_mutex_t *fork;
	pthread_mutex_t eat;
	pthread_mutex_t log;

}				t_data;

typedef struct	s_philo
{
	int			l_fork;
	int			r_fork;
	int			meal_eaten;
	int			philo_id;

	long long	last_eating_time;

	pthread_t	philo_thread;
	
	t_data		*data;

}				t_philo;

/*
 ** [   ERROR.C   ]
 */

int	ft_is_num(int ac, char **av);
int	ft_check_args(int ac, char **av);	
int	ft_error_message(int err);

/*
 ** [   UTILS.C   ]
 */

long long	ft_gettime(void);
int			ft_strlen(const char *str);
long		ft_atoi(const char *str);

/*
 ** [   INIT.C   ]
 */

void	ft_init_data(t_data *data, int ac, char **av);
int		ft_init_mutex(t_data *data);
void	ft_init_philo(t_data *data, t_philo *philo);

/*
 ** [   PHILO.C   ]
 */

int		ft_philo(t_data *data);

/*
 ** [   MAIN.C   ]
 */

int		main(int ac, char **av);

#endif