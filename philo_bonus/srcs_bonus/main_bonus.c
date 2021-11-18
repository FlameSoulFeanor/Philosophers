/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:25:50 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/18 17:15:06 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static	void	end_bonus(t_philo *data, t_all *all)
{
	int i;
	int j;

	i = -1;
	while (++i < data->count_philo)
	{
		waitpid(-1, &(data->status), 0);
		if (data->status != 0)
		{
			j = -1;
			while (++j < data->count_philo)
				kill(all[j].philo_process, SIGTERM);
		}
	}
	sem_close(data->forks);
	sem_close(data->msg);
	sem_unlink("forks");
	sem_unlink("message");
}

static	int	take_forks(t_all *all, t_philo *philo)
{
	int i;

	sem_unlink("forks");
	sem_unlink("message");
	i = -1;
	gettimeofday(&(philo->time_start), NULL);
	while (++i < philo->count_philo)
	{
		philo->forks = sem_open("forks", O_CREAT, S_IRWXU,
				philo->count_philo);
		if (philo->forks == SEM_FAILED)
			error_msg("Can't create semaphore. ", -1);
		all[i].philo_index = i;
		all[i].connect = philo;
		all[i].eating_last_time = philo->time_start;
		all[i].eating_count = 0;
	}
	philo->dead = 0;
	philo->timing_eating = 0;
	philo->msg = sem_open("message", O_CREAT, S_IRWXU, 1);
	if (philo->msg == SEM_FAILED)
		error_msg("Can't create semaphore. ", -1);
	return (0);
}

int	error_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}

int	main(int argc, char **argv)
{
	t_philo data;
	t_all	all[200];
	int		i;

	i = -1;
	if (init_args(&data, argc, argv))
		return (error_msg("Invalid arguments!\n", -1));
	if (take_forks(all, &data))
		return (error_msg("Semaphore can't create.\n", -1));
	while (++i < data.count_philo)
	{
		all[i].philo_process = fork();
		if (all[i].philo_process == -1)
			return (error_msg("Can't create process", -1));
		if (all[i].philo_process == 0)
			philo_life(&(all[i]), &data);		
	}
	end_bonus(&data, all);
	return (0);
}
