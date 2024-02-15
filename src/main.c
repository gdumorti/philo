/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:09 by gdumorti          #+#    #+#             */
/*   Updated: 2024/01/23 16:48:10 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
input: ./philo 5 800 200 200 [5]


*/

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		check_input(&table, argv);
		//2
		//data_init(&table);
		//3 begin
		//dinner_start(&table);
		//4 leaks
		//clean(&table);
		table.test = ft_atoi(argv[1]);
		//ft_printf("OK\n");
	}
	else
		ft_error(GRAS "Wrong input:\n" DEF GREEN"	Please use "ERROR_IN, NULL);
	return (0);
}
