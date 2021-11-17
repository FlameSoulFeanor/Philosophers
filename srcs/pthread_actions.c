/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:09:18 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/17 16:47:38 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	time_to_eat(t_philo *data, t_all *all)
{
	pthread_mutex_lock(&(data->fork[all->right_fork]));
	print_msg("has taken a fork\n", data, all);
	pthread_mutex_lock(&(data->fork[all->left_fork]));
	print_msg("has taken a fork\n", data, all);
	gettimeofday(&(all->eating_lats_time), NULL);
	printf("%d times №%d philo is eating\n",
		all->eating_count, all->philo_index + 1);
	print_msg("is eating\n", data, all);
	all->eating_count++;
	if (all->eating_count
		== data->each_philo_must_eat)
	{
		pthread_mutex_lock(&(data->ate));
		data->timing_eating++;
		pthread_mutex_unlock(&(data->ate));
	}
	my_usleep(data->time_to_eat, data);
	pthread_mutex_unlock(&(data->fork[all->right_fork]));
	pthread_mutex_unlock(&(data->fork[all->left_fork]));
}

static void	*philo_life(void *unknown_str)
{
	t_all	*all;
	t_philo	*data;

	all = (t_all *)unknown_str;
	data = all->connect;
	if (all->philo_index % 2 == 0)
		usleep(150);
	while (1)
	{
		time_to_eat(data, all);
		print_msg("is sleeping\n", data, all);
		my_usleep(data->time_to_sleep, data);
		print_msg("is thinking\n", data, all);
	}
	return (NULL);
}

static	long	check_meal_time(t_all *all)
{
	struct timeval	current_time;

	gettimeofday(&(current_time), NULL);
	return ((current_time.tv_sec - all->eating_lats_time.tv_sec) * 1000
		+ (current_time.tv_usec - all->eating_lats_time.tv_usec) / 1000);
}

static	void	*waiter(void *unknown_str)
{
	t_all	*all;
	t_philo	*data;

	all = (t_all *)unknown_str;
	data = all->connect;
	if (all->philo_index % 2 == 0)
		usleep(150);
	while (1)
	{
		usleep(150);
		if (data->timing_eating >= data->count_philo)
			break ;
		if (check_meal_time(all) >= data->time_to_die)
		{
			pthread_mutex_lock(&(data->msg));
			printf("%ld %d died\n", calc_time(data), all->philo_index + 1);
			data->dead = 1;
			break ;
		}
	}
	return (NULL);
}

void	pthread_actions(t_all *all, t_philo *data)
{
	int	i;

	i = -1;
	while (++i < data->count_philo)
	{
		if (pthread_create(&(all[i].philo_thread), NULL,
				philo_life, (void *)&(all[i])) != 0)
			error_msg("Can't create thread!", -1);
		if (pthread_create(&(all[i].waiter),
				NULL, waiter, (void *)(&all[i])) != 0)
			error_msg("Can't create thread!", -1);
		pthread_detach(all[i].philo_thread);
		pthread_detach(all[i].waiter);
	}
}
