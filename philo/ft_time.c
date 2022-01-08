#include "philosophers.h"

uint64_t	find_the_time(void) // find_the_time
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL))
		ft_error(ERROR);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

uint64_t	actual_time(uint64_t now_time, uint64_t start) //actual_time
{
	return (now_time - start);
}

void check_usleep(uint64_t time)
{
	uint64_t n;

	n = find_the_time();
	while ((find_the_time() - n) < time)
		usleep(500);	
}