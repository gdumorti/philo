/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:19:03 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/26 13:19:04 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*malloc_secure(size_t len)
{
	void	*mallocated;

	if ((mallocated = malloc(len)) == NULL)
		ft_error(GRAS"Error: malloc failed", NULL);
	return (mallocated);
}

static void	handle_error_mutex(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if ((opcode == LOCK || opcode == UNLOCK) && status == EINVAL)
		ft_error(GRAS"The value specified by mutex is invalid.", NULL);
	else if (opcode == INIT && status == EINVAL)
		ft_error(GRAS"The value specified by attr is invalid.", NULL);
	else if (status == EDEADLK)
		ft_error(GRAS"A deadlock would occur if the thread blocked waiting for mutex.", NULL);
	else if (status == EPERM)
		ft_error(GRAS"The current thread does not hold a lock on mutex", NULL);
	else if (status == ENOMEM)
		ft_error(GRAS"The process cannot allocate enough memory to create another mutex.", NULL);
	else if (status == EBUSY)
		ft_error(GRAS"Mutex is locked.", NULL);
}

void	handle_secure_mutex(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		handle_error_mutex(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		handle_error_mutex(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		handle_error_mutex(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		handle_error_mutex(pthread_mutex_destroy(mutex), opcode);
	else
		ft_error(GRAS"Error: opcode problem for mutex"DEF, NULL);
}

static void	handle_error_thread(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		ft_error(GRAS"No ressources to create another thread.", NULL);
	else if (status == EPERM)
		ft_error(GRAS"The caller does not have appropriate permission.", NULL);
	else if (status == EINVAL && opcode == status)
		ft_error(GRAS"The value specified by attr is invalid.", NULL);
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		ft_error(GRAS"The value specified by thread is not joinable.", NULL);
	else if (status == ESRCH)
		ft_error(GRAS"No thread could be found corresponding to that specified by the given thread ID, thread.", NULL);
	else if (status == EDEADLK)
		ft_error(GRAS"A deadlock was detected or the value of thread specifies the calling thread.", NULL);
}

void	handle_secure_thread(pthread_t *thread, void *(foo)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		handle_error_thread(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		handle_error_thread(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_error_thread(pthread_detach(*thread), opcode);
	else
		ft_error(GRAS"Error: opcode problem for handle_thread"DEF, NULL);
}