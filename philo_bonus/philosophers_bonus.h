/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:55:11 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/17 22:05:33 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				count_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				each_philo_must_eat;
	int				status;
	int				timing_eating;
	int				dead;
	sem_t			*forks;
	struct timeval	time_start;
	sem_t			*msg;
}				t_philo;

typedef	struct	s_all
{
	int				philo_index;
	int				eating_count;
	pid_t			philo_process;
	pthread_t		waiter;
	t_philo			*connect;
	struct timeval	eating_last_time;
}	t_all;

int		error_msg(char *msg, int ret);

int		init_args(t_philo *data, int argc, char **argv);
long	calc_time(t_philo *data);

void	my_usleep(int wait_time, t_philo *data);
void	print_msg(char *msg, t_philo *data, t_all *all);
int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);

void	philo_life(t_all *all, t_philo *data);

#endif