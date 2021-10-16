#include <philosophers.h>

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

static int	error_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}

static void take_forks(t_all *all)
{
	int i;

	i = -1;
	while (++i < all->connect->count)
	{
		all[i].philo_index = i;
		all[i].right_fork = i;
		all[i].left_fork = (i + 1) % all->connect->count;
	}
}

long trans_to_ms(t_philo *s_philo)
{
	return ((s_philo->current_time.tv_sec - s_philo->time_start.tv_sec) * 1000
		+ (s_philo->current_time.tv_usec - s_philo->time_start.tv_usec) / 1000);
}

void my_ussleep(t_philo *s_philo, int delta_time)
{
	long till_time;

	gettimeofday(&(s_philo->current_time), NULL);
	till_time = trans_to_ms(s_philo) + delta_time;
	while (trans_to_ms(s_philo) < till_time)
		usleep(100);
}

static void eating_time(t_philo *s_philo, t_all *all)
{
	gettimeofday(&(s_philo->current_time), NULL);
	pthread_mutex_lock(&(s_philo->fork[all->right_fork]));
	printf("%ld %d has taken fork\n", trans_to_ms(s_philo), all->philo_index);
	pthread_mutex_lock(&(s_philo->fork[all->left_fork]));
	printf("%ld %d has taken fork\n", trans_to_ms(s_philo), all->philo_index);
	printf("%ld %d is eating\n", trans_to_ms(s_philo), all->philo_index);
	my_ussleep(s_philo, s_philo->time_to_eat);
	gettimeofday(&(s_philo->current_time), NULL);
	pthread_mutex_unlock(&(s_philo->fork[all->right_fork]));
	pthread_mutex_unlock(&(s_philo->fork[all->left_fork]));
}

void* philo_life(void *philo)
{
	t_philo			*s_philo;
	t_all 			*all;

	all = (t_all *)philo;
	s_philo = all->connect;
	while (1)
	{
		eating_time(s_philo, all);
	}
}

int main(int argc, char **argv)
{
	t_philo	data;
	t_all	all[200];

	if (init_args(&data, argc, argv))
		return (error_msg("Invalid arguments\n", -1));
	all->connect = &data;
	take_forks(all);
	gettimeofday(&(data.time_start), NULL);
	data.current_time = data.time_start;
	if (pthread_create(&(all->philo_thread), NULL, ) != 0);
	return (0);
}
