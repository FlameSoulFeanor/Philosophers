#include <philosophers.h>

static int	error_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}

int main(int argc, char **argv)
{
	t_philo	data;
	t_all	all[250];

	if (init_args(&data, argc, argv))
		return (error_msg("Invalid arguments\n", -1));
	return (0);
}
