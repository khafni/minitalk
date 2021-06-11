/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:03:23 by khafni            #+#    #+#             */
/*   Updated: 2021/06/11 11:57:21 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_byte(pid_t pid, char byte)
{
	int	i;
	int	e;

	i = 0;
	while (i <= 7)
	{
		if ((byte >> i) & 1)
			e = kill(pid, SIGUSR1);
		else
			e = kill(pid, SIGUSR2);
		if (e == -1)
		{
			write(1, "wrong pid\n", 10);
			exit(1);
		}
		usleep(100);
		i++;
	}
}

void	send_ending_metadata(pid_t pid)
{
	char	*ending_metadata;
	int		i;

	i = 0;
	ending_metadata = "!?466e^#7%6<&<%";
	while (ending_metadata[i])
		send_byte(pid, ending_metadata[i++]);
}

void	send_client_pid(pid_t pid)
{
	char	*pid_str;
	int		i;

	pid_str = ft_itoa(getpid());
	i = 0;
	while (pid_str[i])
		send_byte(pid, pid_str[i++]);
	while (i++ < 5)
		send_byte(pid, '?');
	free(pid_str);
}

void	encode(pid_t pid, char *message)
{
	int	i;

	i = 0;
	send_client_pid(pid);
	while (message[i])
	{
		send_byte(pid, message[i]);
		i++;
	}
	send_ending_metadata(pid);
}

void	print_validation_message(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "message was recieved!\n", 22);
		exit(0);
	}	
}
