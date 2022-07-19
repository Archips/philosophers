#include "philo.h"

/* void	*my_turn(void *arg) */
/* { */
/* 	for (int i = 0; i < 8; i ++) */
/* 	{ */
/* 		sleep(1); */
/* 		printf("my turn\n"); */
/* 	} */
/* 	return (NULL); */
/* } */

/* void	your_turn() */
/* { */
/* 	for (int i = 0; i < 3; i ++) */
/* 	{ */
/* 		sleep(2); */
/* 		printf("your turn\n"); */
/* 	} */
/* } */

int	main(int ac, char **av)
{
	t_data	data;
	int		error;

	error = ft_check_args(ac, av);
	if (error)
		return (ft_error_message(error));
	ft_init_data(&data, ac, av);

/* 	t_philo	philo[ft_atoi(argv[1])]; */

/* 	if (argc == 5 || argc == 6) */
/* 		ft_init_philo(argc, argv */
/* 	pthread_t newthread; */

/* 	pthread_create(&newthread, NULL, my_turn, NULL); */

/* 	your_turn(); */

/* 	pthread_join(newthread, NULL); */

	return (0);
}
