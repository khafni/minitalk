/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:08:26 by khafni            #+#    #+#             */
/*   Updated: 2021/06/10 16:36:52 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	remove_pid_from_message(t_rstr rs)
{
	int		i;
	t_rstr	tmp_string;

	i = 5;
	tmp_string = rstr_create(0);
	while (i < rs->len)
	{
		rstr_add(tmp_string, rstr_get(rs, i));
		i++;
	}
	i = 0;
	while (i < rs->len)
	{
		rstr_set(rs, i, rstr_get(tmp_string, i));
		i++;
	}
	rstr_destroy(tmp_string);
	rs->len -= 5;
}

char	*get_client_pid(t_rstr rs)
{	
	t_rstr	rs_tmp;
	int		i;
	char	*result_str;

	i = 0;
	rs_tmp = rstr_create(0);
	while (rstr_get(rs, i) != '?' && i < 5)
	{
		rstr_add(rs_tmp, rstr_get(rs, i));
		i++;
	}
	result_str = rstr_to_cstr(rs_tmp);
	rstr_destroy(rs_tmp);
	return (result_str);
}

void	print_acknowledgment_system_f_message(t_rstr rs)
{
	char	*pid;

	pid = get_client_pid(rs);
	printf("the user with the PID: %s sent this message:\n", pid);
	free(pid);
}

void	send_validation_message(char *pid)
{
	kill(ft_atoi(pid), SIGUSR1);
}

/*
** bitshifting to the left is equivalent to multiplying by 2
*/

void	signal_handler(int signal)
{
	static int				i;
	static unsigned char	byte;
	static t_rstr			rs = NULL;
	char					*pid;

	if (!rs)
		rs = rstr_create(0);
	byte += ((signal == SIGUSR1) << i);
	i++;
	if (i > 7)
	{
		i = 0;
		rstr_add(rs, byte);
		if (!is_str_at_rstr_end(rs, "!?466e^#7%6<&<%"))
		{
			rs->len -= 15;
			print_acknowledgment_system_f_message(rs);
			pid = get_client_pid(rs);
			remove_pid_from_message(rs);
			write(1, rstr_to_cstr(rs), rs->len);
			send_validation_message(pid);
			rstr_destroy(rs);
			rs = NULL;
		}
		byte = 0;
	}
}
