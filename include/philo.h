/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:43:00 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/23 15:43:01 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

/*--- COLORS ---*/

# define RED			"\033[38;2;255;0;0m"		//	red
# define GREEN		"\033[38;2;0;255;0m"		//	green
# define MAG			"\033[38;2;255;38;253m"	//	magenta
# define CYA			"\033[36m"							//	cyan
# define YEL			"\033[33m"							//	yellow
# define WHI			"\033[37m"							//	white
# define BLUE			"\033[34m"							//	blue

#define DEF				"\033[0m"								// reset default color

# define GRAS			"\033[1m"								//	gras
# define SOUL			"\033[4m"								//	souligne
# define ITAL			"\033[3m"								//	italique

# define X				"\xE2\x9C\x97"					//	✗
# define V				"\xE2\x9C\x93"					//	✓
# define WARNING	"\xE2\x9A\xA0"					//	⚠
# define ERROR		"\033[38;2;255;0;0m\xE2\x9C\x97" // red ✗


# define DEBUG_MODE 0

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

/*--- ERROR ---*/

# define ERROR_IN	"./philo 5 800 200 200 [5]"

/*--- PHILO STATES ---*/
typedef	enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}			t_philo_status;


/*--- GET TIME ---*/
typedef	enum	e_time_code
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}			t_time_code;

/*--- OPCODE MUTEX ---*/
typedef enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}		t_opcode;


//-------------

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mutex;

/*----- FORK -----*/

typedef struct s_fork
{
	t_mutex fork;
	int		fork_id;
}				t_fork;


/*----- PHILO -----*/
// ./philo 5 800 200 200 [5]

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool 		full;
	long 		last_meal_time; // time passed from last meal
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mutex		philo_mutex;
	t_table		*table;
	int			test_int;
	long		test_long;
	bool		test_bool;
	t_mutex		test_mutex;
}				t_philo;

/*----- TABLE -----*/
// ./philo 5 800 200 200 [5]

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
	long		start_simulation;
	bool		end_simulation; // arreter le repas
	bool		all_thread_rdy; // synchroniser lancement philo
	long		threads_running_nbr;
	pthread_t	monitor;
	t_fork		*forks; // tableau fourchettes
	t_philo		*philos; 		// tableau philosophers
	t_mutex		table_mutex;
	t_mutex		*write_mutex;
};
// ATTENTION l'ordre est important surtout pour forks et philos sinon SEG FAULT


/*----- PROTOTYPES -----*/
//utils:
long	get_time(int time_code);
void	precise_usleep(long usec, t_table *table);
void	ft_error(char *error, const char *str);
//parsing:
long	ft_atol(const char *str);
void	check_input(t_table *table, char **argv);
//init
void	data_init(t_table *table);
//secure
void	*malloc_secure(size_t len);
void	handle_secure_mutex(t_mutex *mutex, t_opcode opcode);
void	handle_secure_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);
//acces_mutex
void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
long	get_long(t_mutex *mutex, long *value);
void	set_long(t_mutex *mutex, long *dest, long value);
bool	simulation_finished(t_table *table);
//synchro
void	wait_philo_created(t_table *table);
bool	all_threads_running(t_mutex *mutex, long *threads, long philo_nbr);
void	increase_long(t_mutex *mutex, long *value);
void	unsynchronize_philos(t_philo *philo);
//put_status
void	write_status(t_philo_status status, t_philo *philo, bool debug);
//action
void	meal_start(t_table *table);
void	thinking(t_philo *philo, bool pre_simulation);
//monitor
void    *monitor_meal(void *data);
//free_utils
void    clean_mem(t_table *table);

#endif