#include "../includes_bonus/philo_bonus.h"

void    wait_for_meal(t_rules *rules)
{
    int i;

    i = -1;
    while((++i < rules->num_philos))
        sem_wait(rules->check_meal);
    i = -1;
    while((++i < rules->num_philos))
        sem_wait(rules->check_all_ate);
    sem_post(rules->check_death);
    exit(0);
}

void    *wait_for_die(void  *r)
{
    t_rules *rules;
    int i;

    i = 0;
    rules = (t_rules *)r;
    sem_wait(rules->check_death);
   /* while (++i < rules->num_philos)
        kill(rules->philo[i].p_id, 15);*/
    pthread_exit(NULL);
}

void    wait_for_stop(t_rules    *rules)
{
    pthread_t   die;
    pid_t   meal;

    meal = fork();
        if (meal < 0)
            exit(0);
        else if (meal == 0)
            wait_for_meal(rules);
    pthread_create(&die, &rules->attr, wait_for_die, (void *)rules);
    pthread_join(die, NULL);
    kill(meal, 15);
}