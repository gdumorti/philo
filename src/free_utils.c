#include "../include/philo.h"

void    clean_mem(t_table *table)
{
    t_philo *philo;
    int i;

    i = 0;
    while (i < table->philo_nbr)
    {
        philo = table->philos + i;
        handle_secure_mutex(&philo->philo_mutex, DESTROY);
        i++;
    }
    handle_secure_mutex(&table->write_mutex, DESTROY);
    handle_secure_mutex(&table->table_mutex, DESTROY);
    free(table->forks);
    free(table->philos);
}
