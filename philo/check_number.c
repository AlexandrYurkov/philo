#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

int	is_number(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (ft_atoi(n));
}

static int	ft_max(int n)
{
	if (n == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	unsigned int	res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		str++;
	res = 0;
	if (str[0] == '-')
		n = -1;
	else
		n = 1;
	if (str[0] == '-' || str[0] == '+')
		str += 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (i > 10 || res >= 4294967295)
		return (ft_max(n));
	return (n * res);
}