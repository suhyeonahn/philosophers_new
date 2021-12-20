#include "../includes/philo.h"

void    destroy(t_rules *rules)
{
    int i;
    
    pthread_attr_destroy(&rules->attr);
    i  = 0;
      while (i < rules->num_philos)
    {
        pthread_join(rules->philo[i].t_id, NULL);
        i++;
    }
    i = 0;
    while (i < rules->num_philos)
    {
		pthread_mutex_destroy(&rules->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&rules->print_status);
    pthread_mutex_destroy(&rules->check_death);
    pthread_exit(NULL);
}

void    eat(t_philo   *p)
{
    pthread_mutex_lock(&(p->rules->forks[p->lfork_id]));
    if (!print_status(p, p->id, "has ", p->lfork_id + 1))
        return ;
    pthread_mutex_lock(&(p->rules->forks[p->rfork_id]));
    if (!print_status(p, p->id, "has ", p->rfork_id + 1))
        return ;
    if (!print_status(p, p->id, "is eating\n", -42))
        return ;
    gettimeofday(&p->last_meal, NULL);
    usleep(p->rules->time_to_eat);
    pthread_mutex_unlock(&(p->rules->forks[p->lfork_id]));
	pthread_mutex_unlock(&(p->rules->forks[p->rfork_id]));
}

void    *thread(void   *philo)
{
    t_philo   *p;
    t_rules *rules;
    p = (t_philo  *)philo;
    rules = p->rules;
    while (!rules->died && !rules->all_ate)
    {
        eat(p);
        if (rules->all_ate || rules->died)       
            break;      
        if (!print_status(p, p->id, "is sleeping\n", 0))
            break;
        usleep(p->rules->time_to_sleep);
        if (!print_status(p, p->id, "is thinking\n", 0))
            break;
    }
    pthread_exit(NULL);
}

void    create_threads(t_rules *rules)
{
    t_philo   *philo;
    int i;

    philo = rules->philo;
    i = 0;
    while (i < rules->num_philos)
    {
        if (pthread_create(&(philo[i].t_id), &rules->attr, thread, (void *)&philo[i]) < 0)
            exit (0);
        usleep(150);
        i++;
    }
}    

int main(int argc, char **argv)
{
    t_rules rules;
    int ret;

    if ((ret = parse_args(argc, argv, &rules)) < 0)
    {
        write(1, "Error: Wrong argument(s)\n", 25);
        exit (0);
    }
    if ((ret = init_rules(&rules)) < 0)
    {
        write(1, "Error: Initialization failed\n", 29);
        exit (0);
    }
    create_threads(&rules);
    stop_checker(&rules);
    destroy(&rules);
}
