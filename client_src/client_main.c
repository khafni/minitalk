/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:00:21 by khafni            #+#    #+#             */
/*   Updated: 2021/06/11 11:43:17 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{	
		write(1, "client program right usage: ./client PID message\n", 49);
		return (1);
	}
	if (ft_atoi (argv[1]) <= 0)
	{
		write(1, "wrong pid\n", 10);
		exit(1);
	}
	signal(SIGUSR1, print_validation_message);
	encode(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
