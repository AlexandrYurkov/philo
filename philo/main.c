#include "philosophers.h"

void ft_free(t_data *data, pthread_t **potok, int f)
{
	int i;

	i = data->must_eat;
	if(f)
		pthread_mutex_lock(&data->output);
	while (i-- > 0) // i--
		pthread_detach((*potok)[i - 1]); // заменить на [i -1]
	free(*potok);
	return ;	
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (struct_init(argv, &data))
			philos(&data);
	}
	else
		ft_error(ERROR_COUNT);
}