#include "philosophers.h"

void ft_echo(int f, char *s, uint64_t time, t_philo *ph)
{
	sem_wait(ph->data->paint);
	printf("%llu ms %d %s", time, ph->id + 1, s);
	if (f)
		sem_post(ph->data->paint);
}

void ft_error(char *str)
{
	printf("%s", str);
	exit(0);
}