#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR_DATA		"Wrong arguments\n"
# define ERROR_COUNT	"Invalid number of arguments\n"
# define ERROR			"Error\n"
# define LEFT_FORK		"has taken a LEFT fork\n"
# define RIGHT_FORK		"has taken a RIGHT fork\n"
// # define EAT			"\x1b[0;33mis eating\x1b[0m\n"
# define EAT			"is eating\n"
# define DIED			"\x1b[1;31mdied\x1b[0m\n"
# define SLEEP			"is sleeping\n"
# define THINK			"is thinking\n"

typedef struct s_philo
{
	int				id;
	int				count_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	mute;
	uint64_t		last_eat;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				num_of_phil;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	pthread_mutex_t	output;
	int				must_eat;
	uint64_t		first_time;
}				t_data;

int			struct_init(char **argv, t_data *data); 
int			is_number(char *num);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_error(char *str);
uint64_t	find_the_time(void);
uint64_t	actual_time(uint64_t now_time, uint64_t start);
void		ft_echo(int f, char *s, uint64_t time, t_philo *ph);
void 		philos (t_data *data);
void 		ft_free(t_data *data, pthread_t **potok, int f);
//
void		check_usleep(uint64_t time);
void		ft_eat(t_philo *p);
void		ft_sleep(t_philo *p);
void		ft_brain(t_philo *p);

#endif