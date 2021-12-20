#include "../includes/philo.h"

long long	timestamp(struct timeval    t)
{
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	print_status(t_philo *p, int id, char *str, int fork)
{
	pthread_mutex_lock(&(p->rules->check_death));
	if (p->rules->died || p->rules->all_ate)
	{
		pthread_mutex_unlock(&(p->rules->check_death));
		return (0);
	}
	pthread_mutex_lock(&(p->rules->print_status));	
	if (!p->rules->died && !p->rules->all_ate)
	{
        gettimeofday(&p->rules->now, NULL);
		printf("%lli ms ", timestamp(p->rules->now) - timestamp(p->rules->beginning));
		printf("%i ", id + 1);
        printf("%s", str);
        if (fork > 0)
            printf("N.%d fork\n", fork);
		else if (p->rules->num_meals && fork == -42)
			p->eat_count++;
		else if (fork == -444)
		{
			p->rules->died = 1;
			pthread_mutex_unlock(&(p->rules->check_death));
			return (0);
		}
	}
	pthread_mutex_unlock(&(p->rules->check_death));
	pthread_mutex_unlock(&(p->rules->print_status));
	return (1);
}