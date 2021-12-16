#include "../includes_bonus/philo_bonus.h"

long long	timestamp(struct timeval    t)
{
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void    print_status(t_rules *rules, int id, char *str, int has_died)
{
    sem_wait(rules->print_status);
	if (!(rules->died))
	{
        gettimeofday(&rules->now, NULL);
		printf("%lli ms ", timestamp(rules->now) - timestamp(rules->beginning));
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	if (!has_died)
    	sem_post(rules->print_status);
}