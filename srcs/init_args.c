/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:09:32 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/08 20:09:35 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int check_args(t_philo *data)
{
	if (data->count_philo > 200 || data->count_philo < 0)
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
