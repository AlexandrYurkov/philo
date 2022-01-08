#include "philosophers.h"

void ft_eat(t_philo *p)
{
    pthread_mutex_lock(p->left);
	ft_echo(1, LEFT_FORK, actual_time(find_the_time(), p->data->first_time), p);
	pthread_mutex_lock(p->right);
	ft_echo(1, RIGHT_FORK, actual_time(find_the_time(), p->data->first_time), p);
	p->last_eat = find_the_time();
	// pthread_mutex_lock(&p->mute);
	ft_echo(1, EAT, actual_time(p->last_eat, p->data->first_time), p);
	pthread_mutex_unlock(&p->mute);
	check_usleep(p->data->time_eat);
	p->count_eat++;
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
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