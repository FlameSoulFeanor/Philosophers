/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:58:37 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/17 21:26:03 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	calc_time(t_philo *data)
{
	struct timeval	current_time;

	gettimeofday(&(current_time), NULL);
	return ((current_time.tv_sec - data->time_start.tv_sec) * 1000
		+ (current_time.tv_usec - data->time_start.tv_usec) / 1000);
}

static int	check_args(t_philo *data)
{
	if (data->count_philo > 200 || data->count_philo < 0
		|| data->time_to_die < 60 || data->time_to_sleep < 60
		|| data->time_to_eat < 60)
		return (-1);
	else
		return (0);
}

int	init_args(t_philo *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (error_msg("Can't initialize arguments. ", -1));
	else
	{
		data->count_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
		data->each_philo_must_eat = ft_atoi(argv[5]);
	else if (argc == 5)
		data->each_philo_must_eat = 0;
	data->dead = 0;
	return (check_args(data));
}
