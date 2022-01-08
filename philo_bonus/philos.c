#include "philosophers.h"

static void *check_mon(void *p)
{
    t_philo *tmp;

    tmp = (t_philo *)p;
    while (1)
    {
        if (actual_time(find_the_time(), tmp->last_eat) >=
            tmp->data->time_die)
        {
            ft_echo(0, DIED, actual_time(find_the_time(), tmp->data->first_time), tmp);
            exit(2);
        }
        if (tmp->data->must_eat > 0 && tmp->count_eat >= tmp->data->must_eat)
        {
            sem_post(tmp->data->fork);
            sem_post(tmp->data->fork);
            exit(3);
        }
        usleep(50);
    }
}

void *imitation(t_philo *p)
{
    pthread_t mon;

    p->last_eat = p->data->first_time;
    pthread_create(&mon, NULL, check_mon, p);
    ft_brain(p);
    if (p->id % 2 != 0)
        check_usleep(p->data->time_eat / 2);
    while (1)
    {
        ft_eat(p);
        ft_sleep(p);
        ft_brain(p);
    }
}

static void proc_init(t_data *data, t_philo **p)
{
    int i;
    int n;
    int c;

    n = data->num_of_phil;
    data->first_time = find_the_time();
    i = -1;
    while (++i < n)
    {
        (*p)[i].pid = fork();
        if ((*p)[i].pid == 0)
            imitation(&((*p)[i]));
    }
    i = -1;
    while (++i < n)
    {
        waitpid(-1, &c, 0);
        if (WEXITSTATUS(c) == 2)
            return (proc_kill(*p, n));
    }
}

void ft_open(t_data *data)
{
    data->fork = sem_open("fork", O_CREAT, 0666, data->num_of_phil);
    data->paint = sem_open("paint", O_CREAT, 0666, 1);
    data->dumb = sem_open("dumb", O_CREAT, 0666, 1);
    if (data->fork == SEM_FAILED || data->paint == SEM_FAILED || data->dumb == SEM_FAILED)
        ft_error(ERROR);
}

void philos(t_data *data)
{
    t_philo *p;

    sem_unlink("fork");
    sem_unlink("paint");
    sem_unlink("dumb");
    p = malloc(sizeof(t_philo) * data->num_of_phil);
    if (!p)
        ft_error(ERROR);
    ft_open(data);
    struct_init_ph(data, &p);
    proc_init(data, &p);
    sem_unlink("fork");
    sem_unlink("paint");
    sem_unlink("dumb");
    free(p);
}
