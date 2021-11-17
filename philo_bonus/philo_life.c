/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:27:26 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/17 22:06:34 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	void	eat_time(t_all *all, t_philo *data)
{
	
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
