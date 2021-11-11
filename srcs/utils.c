/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:13:06 by hfunctio          #+#    #+#             */
/*   Updated: 2021/11/11 20:17:52 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	my_usleep(int wait_time, t_philo *data)
{
	long	end_time;
	int		i;

	end_time = calc_time(data) + wait_time;
	i = 200 + (data->count_philo * 4);
	while (calc_time(data) < end_time)
		usleep(i);
}

long	calc_time(t_philo *data)
{
	struct timeval	current_time;

	gettimeofday(&(current_time), NULL);
	return ((current_time.tv_sec - data->time_start.tv_sec) * 1000
		+ (current_time.tv_usec - data->time_start.tv_usec) / 1000);
}

void	print_msg(char *msg, t_philo *data, t_all *all)
{
	pthread_mutex_lock(&(data->msg));
	printf("%ld %d %s\n", calc_time(data), all->philo_index +1, msg);
	pthread_mutex_unlock(&(data->msg));
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
	return (res = minus == 1 ? -res : res);
}

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
