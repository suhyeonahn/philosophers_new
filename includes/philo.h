#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <pthread.h>
#include <limits.h>

struct s_rules;

typedef struct s_philosopher
{
    int id;
    int lfork_id;
    int rfork_id;
    int eat_count;
    struct timeval  last_meal;
    pthread_t   t_id;
    struct s_rules  *rules;
}   t_philosopher;

typedef struct s_rules
{
    int num_philos;
    int num_meals;
    long long time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int died;
    int all_ate;
    pthread_mutex_t forks[250];
    pthread_mutex_t print_status;
    pthread_mutex_t check_death;
    pthread_attr_t attr;
    t_philosopher   philo[250];
    struct timeval  beginning;
    struct timeval  now;
}   t_rules;

void        create_threads(t_rules *rules);
void        *thread(void   *philo);
void        eat(t_philosopher   *p);
void        destroy(t_rules *rules);

void        death(t_rules *rules, int i);
void        stop_checker(t_rules *rules);

long long	timestamp(struct timeval    t);
void        print_status(t_rules *rules, int id, char *str, int fork);

void        init_philosophers(t_rules    *rules);
int         init_mutex(t_rules  *rules);
int         init_rules(t_rules  *rules);

int         parse_args(int argc, char **argv, t_rules *rules);

int         ft_strlen(const char *str);
long long   ft_atoi(const char *str);

#endif