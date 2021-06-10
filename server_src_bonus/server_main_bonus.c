/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:23 by khafni            #+#    #+#             */
/*   Updated: 2021/06/10 21:01:03 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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
	byte += ((signal == SIGUSR1) << i++);
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

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
