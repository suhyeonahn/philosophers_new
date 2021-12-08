#include "../includes/philo.h"

void    init_philosophers(t_rules    *rules)
{
    int i;

    i = 0;
    while (i < rules->num_philos)
    {
        rules->philo[i].id = i;
        rules->philo[i].lfork_id = i;
        rules->philo[i].rfork_id = (i + 1) % rules->num_philos;
        rules->philo[i].eat_count = 0;
        rules->philo[i].rules = rules;
        gettimeofday(&rules->philo[i].last_meal, NULL); 
        i++;
    }
}

int init_mutex(t_rules  *rules)
{
    int i;

    i = 0;
    while (i < rules->num_philos)
    {
        if (pthread_mutex_init(&(rules->forks[i]), NULL) != 0)
            return (-1);
        i++;
    }
    if (pthread_mutex_init(&(rules->print_status), NULL) != 0)
        return (-1);
    if (pthread_mutex_init(&(rules->check_death), NULL) != 0)
        return (-1);
    return (0);
}

int    init_rules(t_rules  *rules)
{
    rules->died = 0;
    rules->all_ate = 0;
    gettimeofday(&rules->beginning, NULL);
    if (init_mutex(rules) < 0)
        return (-1);
    init_philosophers(rules);
    if (pthread_attr_init(&rules->attr) != 0)
        return (-1);
    pthread_attr_setdetachstate(&rules->attr, PTHREAD_CREATE_JOINABLE);
    return (0);
}