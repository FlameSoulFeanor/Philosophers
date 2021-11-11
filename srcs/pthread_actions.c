/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:09:18 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/11 20:10:35 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	time_to_eat(t_philo *data, t_all *all)
{
	pthread_mutex_lock(&(data->fork[all->right_fork]));
	print_msg("has taken a fork\n", data, all);
	pthread_mutex_lock(&(data->fork[all->left_fork]));
	print_message("has taken a fork\n", data, all);
	gettimeofday(&(all->eating_lats_time), NULL);
	print_message("is eating\n", data, all);
	all->eating_count++;
	if (all->eating_count
		== data->each_philo_must_eat)
	{
		pthread_mutex_lock(&(data->ate));
		data->timing_eating++;
		pthread_mutex_unlock(&(data->ate));
	}
	ft_usleep(data->time_to_eat, data);
	pthread_mutex_unlock(&(data->fork[all->right_fork]));
	pthread_mutex_unlock(&(data->fork[all->left_fork]));
}

static void *philo_life(void *unknown_str)
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

static void *waiter(void *unknown_str)
{
	t_all 	*all;
	t_philo *data;

	all = (t_all *)unknown_str;
	data = all->connect;
	if (all->philo_index % 2 == 0)
		usleep(150);
	while (1)
	{
		
	}
	while (1)
		;
	return (NULL);
}

void	pthread_actions(t_all *all, t_philo *data)
{
	int i;

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
