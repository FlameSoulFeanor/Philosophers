#include <philosophers.h>

size_t ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	error_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}

int main(int argc, char **argv)
{
	t_all philos[250];
	t_actions actions;

	if (init_args(&actions, argc, argv))
		return (error_msg("Invalid arguments\n", -1));
	return (0);
}
