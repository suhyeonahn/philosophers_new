#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>

struct s_rules;

typedef struct s_philo
{
    int id;
    int eat_count;
    struct timeval  last_meal;
    pid_t   p_id;
    pthread_t   t_id;
    pthread_t   meal_check_t_id;
    struct s_rules  *rules;
}   t_philo;

typedef struct s_rules
{
    int num_philos;
    int num_meals;
    long long time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int died;
    int all_ate;
    sem_t   *fork;
    sem_t   *print_status;
    sem_t   *check_meal;
    sem_t   *check_death;
    sem_t   *check_all_ate;
    pthread_attr_t attr;
    t_philo   philo[250];
    struct timeval  beginning;
    struct timeval  now;
}   t_rules;

void    create_philo_process(t_rules *rules);
void    philo_process(t_philo *philo);
void    eat(t_philo  *p);
void    *philo_acts(void *philo);
void    destroy(t_rules *rules);

void    death_checker(t_philo *p);
void    *meal_checker(void *philo);

int	ft_strlen(const char *str);
long long	ft_atoi(const char *str);

void    init_philos(t_rules    *rules);
int init_semaphore(t_rules  *rules);
int    init_rules(t_rules  *rules);

int    parse_args(int argc, char **argv, t_rules *rules);

void    wait_for_meal(t_rules *rules);
void    *wait_for_die(void  *r);
void    wait_for_stop(t_rules    *rules);

long long	timestamp(struct timeval    t);
void    print_status(t_rules *rules, int id, char *str, int has_died);


#endif