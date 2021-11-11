/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:09:25 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/11 20:26:43 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** Один или несколько философов сидят за круглым столом и
** делают одно трех действий:
** 1. Едят
** 2. Думают
** 3. Спят
** 
** Во время еды они не думают и, конечно же, думая, они не едят и не спят.
**
** Философы сидят вокруг круглого стола с тарелкой спагетти в центре стола.
**
** На столе есть вилки.
**
** Предполагается, что филосов должен есть двумя вилками,
** по одной на каждую руку.
**
** Философы никогда не должны голодать. Каждый философ должен поесть.
**
** Философы не разговаривают друг с другом. Философы не знают,
** когда усирает другой философ.
**
** Когда филосов заканчивает есть, он убирает вилку и начинает спать.
**
** Когда философ засыпает, он начинает думать. 
** Программа останавливается, когда философ умирает.
**
** Аргументы на вход программы:
** 1. numbers_of_philosophers - кол-во филосов, а также кол-во вилок.
** 2. time_to_die - время в миллисекундах,
** если филосов не начинает есть после последнего приема пищи,
** или после старта работы программы, филосов умирает.
** 3. time_to_eat - время в миллисекундах, которое требуетсся философу,
** чтобы поесть.В течении этого времени, нужно деражть две вилки.
** 4. time_to_sleep - время, в течении которого философ будет спать.
** 5. number_of_times_each_philosopher_must_eat - если все философы
**	  съедают хотя бы "5.", симуляция остановится. 
**
** Каждому философфу следует присвоить число от 1 до numbers_of_philosophers.
**
** usleep - 
** gettimeofday-
** pthread_create - 
** pthread_detach -
** pthread_join - 
** pthread_mutex_init - 
** pthread_mutex_destroy - 
** pthread_mutex_lock - 
** pthread_mutex_unlock -
**
*/

static int	take_forks(t_all *all, t_philo *philo)
{
	int i;

	i = -1;
	gettimeofday(&(philo->time_start), NULL);
	while (++i < philo->count_philo)
	{
		if (pthread_mutex_init(&(philo->fork[i]), NULL) != 0)
			return (error_msg("Can't create mutex. ", -1));
		all[i].philo_index = i;
		all[i].right_fork = i;
		all[i].left_fork = (i + 1) % philo->count_philo;
		all[i].connect = philo;
		all[i].eating_lats_time = philo->time_start;
		all[i].eating_count = 0;
	}
	philo->dead = 0;
	philo->timing_eating = 0;
	if (pthread_mutex_init(&(philo->msg), NULL) != 0)
		return (error_msg("Can't create mutex. ", -1));
	if (pthread_mutex_init(&(philo->ate), NULL) != 0)
		return (error_msg("Can't create mutex. ", -1));
	return (0);
}

int	error_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}

void	end(t_philo *data)
{
	int i;

	while (data->dead != 1 && data->timing_eating
		!= data->count_philo)
		;
	i = -1;
	while (++i < data->count_philo)
		pthread_mutex_destroy(&(data->fork[i]));
	pthread_mutex_destroy(&(data->msg));
}

int main(int argc, char **argv)
{
	t_philo	data;
	t_all	all[200];

	if (init_args(&data, argc, argv))
		return (error_msg("Invalid arguments!\n", -1));
	if (take_forks(all, &data))
		return (error_msg("Mutex can't initialize!\n", -1));
	pthread_actions(all, &data);
	end(&data);
	return (0);
}
