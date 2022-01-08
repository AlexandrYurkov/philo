#include "philosophers.h"

void proc_kill(t_philo *p, int n)
{
	while (n > 0)
	{
		kill(p[n - 1].pid, SIGHUP);
		n--;
	}
	return;
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 5 || argc == 6)
	{
		if (struct_init(argv, &data))
			philos(&data);
	}
	else
		ft_error(ERROR_COUNT);
}