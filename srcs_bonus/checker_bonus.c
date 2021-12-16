#include "../includes_bonus/philo_bonus.h"

void    death_checker(t_philo *p)
{
    while (!p->rules->died && !p->rules->all_ate)
    {
        gettimeofday(&p->rules->now, NULL);
        if ((timestamp(p->rules->now) -
        timestamp(p->last_meal)) >= (p->rules->time_to_die / 1000))
        {
            print_status(p->rules, p->id, "has died", 1);
            p->rules->died = 1;
            sem_post(p->rules->check_death);
        }
    }
}

void    *meal_checker(void *philo)
{
    t_philo *p;

    p = (t_philo *)philo;
    if (p->rules->num_meals)
    {
        while (!p->rules->died)
        {
            if (p->eat_count == p->rules->num_meals)
            {
                sem_post(p->rules->check_meal);
                break;
            }
        }
        sem_post(p->rules->check_all_ate);
        p->rules->all_ate = 1;
    }
    pthread_exit(NULL);
}