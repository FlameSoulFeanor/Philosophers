#include <philosophers.h>

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

static int check_args(t_actions *actions)
{
	if (actions->count > 200 || actions->time_to_die < 60
		|| actions->time_to_die < 60 || actions->time_to_sleep < 60
		|| actions->each_eat_at_least < 0 || actions->count <= 0)
		return (-1);
	else
		return (0);
}

int	init_args(t_actions *actions, int argc, char **argv)
{
	if (argc < 5)
	{
		printf("%s\n", "Error: can't init arguments\n");
		return (-1);
	}
	else
	{
		actions->count = ft_atoi(argv[1]);
		actions->time_to_die = ft_atoi(argv[2]);
		actions->time_to_eat = ft_atoi(argv[3]);
		actions->time_to_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
		actions->each_eat_at_least = ft_atoi(argv[5]);
	else if (argc == 5)
		actions->each_eat_at_least = 0;
	else
		return (-1);
	return (check_args(actions));
}
