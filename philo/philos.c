#include "philosophers.h"

void *imitation (void *p)
{
    t_philo *tmp;

    tmp = (t_philo *)p;
    tmp->last_eat = tmp->data->first_time;
    ft_brain(tmp);
    if (tmp->id % 2 != 0)
        check_usleep(tmp->data->time_eat / 2);
    while (1)
    {
        ft_eat(tmp);
        ft_sleep(tmp);
        ft_brain(tmp);
    }
    
}

void check_rip (t_data *data, t_philo **p, pthread_t ** potok)
{
    int i;
    int ch;

    check_usleep(data->time_die / 2);
    while (1)
    {
        i = -1;
        ch = 1;
        while (++i < data->num_of_phil)
        {
            if (actual_time(find_the_time(), (*p)[i].last_eat) >= data->time_die)
            {
                ft_echo(0, DIED, actual_time(find_the_time(),
                    data->first_time), &(*p)[i]);
                return (ft_free(data, potok, 0));
            }
            if (data->must_eat > 0 && (*p)[i].count_eat < data->must_eat)
                ch = 0;
        }
        if (data->must_eat > 0 && ch == 1)
            return (ft_free(data, potok, 1));
    }
}

void potok(t_data *data, t_philo **p)
{
    int i;
    int n;
    pthread_t *potok;

    i = -1;
    n = data->num_of_phil;
    potok = malloc(sizeof(pthread_t) * n);
    if(!potok)
        ft_error(ERROR);
    data->first_time = find_the_time();
    while (++i < n)
        pthread_create(&potok[i], NULL, imitation, &((*p)[i]));

    check_rip(data, p, &potok);
}

void init_time_eat (t_data *data, t_philo **p, pthread_mutex_t **mut)
{
    int i;
    int n;

    i = -1;
    n = data->num_of_phil;
    while (++i < n)
    {
        if (pthread_mutex_init(&(*mut)[i], NULL) != 0 ||
            pthread_mutex_init(&(*p)[i].mute, NULL) != 0)
            ft_error(ERROR);
        (*p)[i].id = i;
        (*p)[i].count_eat = 0;
        (*p)[i].data = data;
        (*p)[i].left = &(*mut)[i];
        if (i == n - 1)
            (*p)[0].right = (*p)[i].left;
        else
            (*p)[i + 1].right = &(*mut)[i];
    }
}

void philos (t_data *data)
{
    t_philo *p;
    pthread_mutex_t *mut;

    p = malloc(sizeof(t_philo) * data->num_of_phil);
    mut = malloc(sizeof(pthread_mutex_t) * data->num_of_phil);
    if(!p || !mut)
        ft_error(ERROR);
    if(p && mut)
    {
        init_time_eat(data, &p, &mut);
        potok(data, &p);
    }
    else
        ft_error(ERROR);
}