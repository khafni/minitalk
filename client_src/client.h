/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:54:58 by khafni            #+#    #+#             */
/*   Updated: 2021/06/10 15:01:29 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../rstr/rstr.h"
# include "../tools/tools.h"

void	send_byte(pid_t pid, char byte);
void	send_ending_metadata(pid_t pid);
void	send_client_pid(pid_t pid);
void	print_validation_message(int sig);
void	encode(pid_t pid, char *message);
#endif