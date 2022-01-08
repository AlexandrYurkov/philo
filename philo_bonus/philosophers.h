#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define ERROR_DATA "Wrong arguments\n"
#define ERROR_COUNT "Invalid number of arguments\n"
#define ERROR "Error\n"
#define LEFT_FORK "has taken LEFT fork\n"
#define RIGHT_FORK "has taken RIGHT fork\n"
#define EAT "\x1b[0;33mis eating\x1b[0m\n"
#define DIED "\x1b[1;31mdied\x1b[0m\n"
#define SLEEP "is sleeping\n"
#define THINK "is thinking\n"

typedef struct s_philo
{
	int id;
	int count_eat;
	int flag;
	pid_t pid;
	uint64_t last_eat;
	struct s_data *data;
} t_philo;

typedef struct s_data
{
	int num_of_phil;
	int must_eat;
	uint64_t time_die;
	uint64_t time_eat;
	uint64_t time_sleep;
	uint64_t first_time;
	sem_t *fork;
	sem_t *paint;
	sem_t *dumb;

} t_data;

int struct_init(char **argv, t_data *data);
void struct_init_ph(t_data *data, t_philo **p);
int is_number(char *num);
int ft_isdigit(int c);
int ft_atoi(const char *str);
void ft_error(char *str);
uint64_t find_the_time(void);
uint64_t actual_time(uint64_t now_time, uint64_t start);
void ft_echo(int f, char *s, uint64_t time, t_philo *ph);
void philos(t_data *data);
void proc_kill(t_philo *p, int n);
void check_usleep(uint64_t time);
void ft_eat(t_philo *p);
void ft_sleep(t_philo *p);
void ft_brain(t_philo *p);

#endif