#include "../includes_bonus/philo_bonus.h"

int    parse_args(int argc, char **argv, t_rules *rules)
{
    if (!((argc == 5) || (argc == 6)))
        return (-1);
    if ((rules->num_philos = ft_atoi(argv[1])) < 2)
        return (-1);
    if ((rules->time_to_die = ft_atoi(argv[2]) * 1000) < 0)
        return (-1);
    if ((rules->time_to_eat = ft_atoi(argv[3]) * 1000) < 0)
        return (-1);
    if ((rules->time_to_sleep = ft_atoi(argv[4]) * 1000) < 0)
        return (-1);
    if (argc == 6)
    {
        if ((rules->num_meals = ft_atoi(argv[5])) <= 0)
            return (-1);
    }
    else
        rules->num_meals = 0;
    return (0);
}