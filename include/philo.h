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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>
#include "../ft_printf/include/ft_printf.h"
#include "../ft_printf/libft/libft.h"

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

/*--- PHILO STATES ---*/
typedef	enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;


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

/*--- GET TIME ---*/
typedef	enum	e_time_code
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}			t_time_code;

/*--- ERROR ---*/

# define ERROR_IN	"./philo 5 800 200 200 [5]"

//-------------

typedef pthread_mutex_t	t_mutex;

typedef struct s_table	t_table;


/*----- FORK -----*/

typedef struct s_fork
{
	t_mutex fork;
	int			fork_id;
}							t_fork;


/*----- PHILO -----*/
// ./philo 5 800 200 200 [5]

typedef struct s_philo
{
	int	id;
	long meals_counter;
	bool full;
	long last_meal_time; // time passed from last meal
	t_fork	*first_fork;
	t_fork	*second_fork;
	pthread_t	thread_id;
	t_table	*table;
}			t_philo;

/*----- TABLE -----*/
// ./philo 5 800 200 200 [5]

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals; // [5] FLAG if -1
	long		start_simulation;
	bool		end_simulation; // a philo dies or all philo full
	bool		all_thread_rdy; // synchro philo
	t_mutex	table_mutex;	//
	t_mutex	*write_mutex;
	t_fork	*forks; // array forks
	t_philo	*philos; // array philosophers
	int			test;
};

/*----- PROTOTYPES -----*/
//utils:
long	get_time(t_time_code time_code);
void	precise_usleep(long usec, t_table *table)
void	ft_error(char *error, const char *str);
//parsing:
long	ft_atol(const char *str);
void	check_input(t_table *table, char **argv);
//init
void	data_init(t_table *table);
//secure
void	*malloc_secure(size_t len);
static void	handle_error_mutex(int status, t_opcode opcode);
void	handle_secure_mutex(t_mutex *mutex, t_opcode opcode);
static void	handle_error_thread(int status, t_opcode opcode);
void	handle_secure_thread(pthread_t *thread, void *(foo)(void *), void *data, t_opcode opcode);
//acces_mutex
void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
long	get_long(t_mutex *mutex, long *value);
void	set_long(t_mutex *mutex, long *dest, long *value);
bool	simulation_finished(t_table *table);
//synchro
void	wait_philo_created(t_table *table);
//put_status
void	write_status(t_philo_status status, t_philo *philo, bool debug);
static void	write_status_debug(t_philo_status status, t_philo *philo, long passed);




#endif