/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:26:08 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/17 21:26:34 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	my_usleep(int wait_time, t_philo *data)
{
	long	end_time;
	int		i;

	end_time = calc_time(data) + wait_time;
	i = 200 + (data->count_philo * 4);
	while (calc_time(data) < end_time)
		usleep(i);
}

void	print_msg(char *msg, t_philo *data, t_all *all)
{
	sem_wait(data->msg);
	printf("%ld %d %s\n", calc_time(data), all->philo_index + 1, msg);
	sem_post(data->msg);
}

static	int	ret_value(unsigned long res, int minus)
{
	if (minus)
		return (-res);
	else
		return (res);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				minus;

	i = 0;
	res = 0;
	minus = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807)
	{
		if (minus)
			return (0);
		return (-1);
	}
	return (ret_value(res, minus));
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
