#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_actions
{
	size_t count;
	size_t time_to_die;
	size_t time_to_sleep;
	size_t time_to_eat;
	ssize_t each_eat_at_least;
}	t_actions;

typedef struct s_all
{
	int dead;
	t_actions *actions;
}	t_all;

int	init_args(t_actions *actions, int argc, char **argv);
int	ft_atoi(const char *str);

#endif