#include <philosophers.h>

static int check_args(t_philo *data)
{
	if (data->count > 200 || data->time_to_die < 60
		|| data->time_to_die < 60 || data->time_to_sleep < 60
		|| data->each_philo_must_eat < 0 || data->count <= 0)
		return (-1);
	else
		return (0);
}

int	init_args(t_philo *data, int argc, char **argv)
{
	if (argc < 5)
	{
		printf("%s\n", "Error: can't init arguments\n");
		return (-1);
	}
	else
	{
		data->count = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
		data->each_philo_must_eat = ft_atoi(argv[5]);
	else if (argc == 5)
		data->each_philo_must_eat = 0;
	else
	{
		printf("%s\n", "Error: can't init arguments\n");
		return (-1);
	}
	data->is_dead = 0;
	return (check_args(data));
}
