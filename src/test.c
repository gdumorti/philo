#include <unistd.h>
#include <stdio.h>
#include <limits.h>

long	ft_atol(const char *str)
{
	int	i;
	long num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
			return (-1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + str[i++] - 48;
		if (num < 0) //overflow
			return (-1);
		if (num > INT_MAX)
			return (-1);
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i])
		return (-1);
	return (num);
}

int main(int argc, char **argv)
{
	long	nb;

	nb = ft_atol(argv[1]);
	printf("long = %ld\n", nb);
	return (0);
}