/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:51:51 by khafni            #+#    #+#             */
/*   Updated: 2021/06/10 16:10:16 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../rstr/rstr.h"
# include "../tools/tools.h"

void	remove_pid_from_message(t_rstr rs);
char	*get_client_pid(t_rstr rs);
void	print_acknowledgment_system_f_message(t_rstr rs);
void	send_validation_message(char *pid);
void	signal_handler(int signal);

#endif