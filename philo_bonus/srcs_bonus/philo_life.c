/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:27:26 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/18 17:15:58 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static	int	check_meal(t_all *all)
{
	struct timeval	current_time;

	gettimeofday(&(current_time), NULL);
	return ((current_time.tv_sec - all->eating_last_time.tv_sec) * 1000
		+ (current_time.tv_usec - all->eating_last_time.tv_usec) / 1000);
}

static	void	*waiter_bonus(void *tmp_philo)
{
	t_all	*all;
	t_philo	*data;

	all = (t_all *)tmp_philo;
	data = all->connect;
	while (1)
	{
		usleep(150);
		if (check_meal(all) >= data->time_to_die)
		{
			sem_wait(data->msg);
			printf("%ld %d died\n", calc_time(data), all->philo_index + 1);
			data->dead = 1;
			exit (1);
		}
	}
	return (NULL);
}

static	void	eat_time(t_all *all, t_philo *data)
{
	sem_wait(data->forks);
	print_msg("has taken a fork\n", data, all);
	sem_wait(data->forks);
	print_msg("has taken a fork\n", data, all);
	gettimeofday(&(all->eating_last_time), NULL);
	print_msg("is eating\n", data, all);
	all->eating_count++;
	my_usleep(data->time_to_eat, data);
	sem_post(data->forks);
	sem_post(data->forks);
	if (all->eating_count == data->each_philo_must_eat)
		exit (0);
}

void	philo_life(t_all *all, t_philo *data)
{
	if (pthread_create(&(all->waiter),
			NULL, waiter_bonus, (void *)(all)) != 0)
		error_msg("Can't create thread.", -1);
	pthread_detach(all->waiter);
	if (all->philo_index % 2 == 0)
		usleep(150);
	while (1)
	{
		eat_time(all, data);
		print_msg("is sleeping\n", data, all);
		my_usleep(data->time_to_sleep, data);
		print_msg("is thinking\n", data, all);
	}
}
