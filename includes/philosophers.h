#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				count;
	int				time_to_die;
	int 			time_to_sleep;
	int				time_to_eat;
	int				each_philo_must_eat;
	int				dead;
	struct timeval	time_start;
	pthread_mutex_t	fork[250];
}	t_philo;

typedef struct s_all
{
	int			left_fork;
	int			right_fork;
	pthread_t	philo_thread;
	t_philo		*connect;
}	t_all;

int		init_args(t_philo *data, int argc, char **argv);
int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);

#endif