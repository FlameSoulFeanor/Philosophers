/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:13:06 by hfunctio          #+#    #+#             */
/*   Updated: 2021/10/04 15:14:16 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

size_t ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
