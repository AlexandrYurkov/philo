#include "philosophers.h"

void	ft_echo(int f, char *s, uint64_t time, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->output);
	printf("%llu ms %d %s", time, ph->id + 1, s);
	if (f)
		pthread_mutex_unlock(&ph->data->output);
}

void	ft_error(char *str)
{
	printf("%s", str);
	exit(0);
}