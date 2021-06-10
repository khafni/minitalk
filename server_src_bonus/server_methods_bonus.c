/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_methods_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:08:26 by khafni            #+#    #+#             */
/*   Updated: 2021/06/10 21:02:45 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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
	write(1, "the user with the PID: ", 23);
	write(1, pid, ft_strlen(pid));
	write(1, " sent this message:\n", 20);
	free(pid);
}

void	send_validation_message(char *pid)
{
	kill(ft_atoi(pid), SIGUSR1);
	usleep(150);
}
