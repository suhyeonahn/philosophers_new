#include "../includes/philo.h"

long long	timestamp(struct timeval    t)
{
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void    print_status(t_rules *rules, int id, char *str, int fork)
{
	pthread_mutex_lock(&(rules->print_status));
	if (!rules->died && !rules->all_ate)
	{
        gettimeofday(&rules->now, NULL);
		printf("%lli ms ", timestamp(rules->now) - timestamp(rules->beginning));
		printf("%i ", id + 1);
        printf("%s", str);
        if (fork > 0)
            printf("N.%d fork\n", fork);
	}
	pthread_mutex_unlock(&(rules->print_status));
}