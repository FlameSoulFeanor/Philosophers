/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:25:29 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/16 20:25:34 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_program_bonus(t_condition *condition, t_philo *philo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < condition->number_of_philosophers)
	{
		waitpid(-1, &(condition->status), 0);
		if (condition->status != 0)
		{
			j = -1;
			while (++j < condition->number_of_philosophers)
				kill(philo[j].philo_process, SIGTERM);
		}
	}
	sem_close(condition->forks);
	sem_close(condition->message);
	sem_unlink("forks");
	sem_unlink("message");
}
