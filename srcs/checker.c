#include "../includes/philo.h"

void    death(t_rules *rules, int i)
{
    if (!print_status(&rules->philo[i], rules->philo[i].id, "has died\n", -444))
        return ;
}

void    stop_checker(t_rules *rules)
{
    int i;
    int ate;

    while (!rules->all_ate && !rules->died)
    {
        i = 0;
        ate = 0;
        while (i < rules->num_philos)
        {
            gettimeofday(&rules->now, NULL);
            if ((timestamp(rules->now) -
            timestamp(rules->philo[i].last_meal)) > (rules->time_to_die / 1000))
                death(rules, i);
            if (rules->num_meals && rules->philo[i].eat_count >= rules->num_meals)
                ate++;
            i++;
        }
        if (rules->num_meals && ate == rules->num_philos)
            rules->all_ate = 1;
    }
}
