#include "philosophers.h"

void ft_eat(t_philo *p)
{
	sem_wait(p->data->dumb);
	sem_wait(p->data->fork);
	ft_echo(1, LEFT_FORK, actual_time(find_the_time(), p->data->first_time), p);
	sem_wait(p->data->fork);
	ft_echo(1, RIGHT_FORK, actual_time(find_the_time(), p->data->first_time), p);
	sem_post(p->data->dumb);
	p->last_eat = find_the_time();
	ft_echo(1, EAT, actual_time(p->last_eat, p->data->first_time), p);
	check_usleep(p->data->time_eat);
	p->count_eat++;
	sem_post(p->data->fork);
	sem_post(p->data->fork);
}

void ft_sleep(t_philo *p)
{
	ft_echo(1, SLEEP, actual_time(find_the_time(), p->data->first_time), p);
	check_usleep(p->data->time_sleep);
}

void ft_brain(t_philo *p)
{
	ft_echo(1, THINK, actual_time(find_the_time(), p->data->first_time), p);
}