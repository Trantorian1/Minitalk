/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_server.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:39:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 14:16:55 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SERVER_H
# define S_SERVER_H

# include "e_state.h"
# include "s_message.h"
# include <stdint.h>
# include <stdbool.h>
#include <unistd.h>

/**
 * @brief A server responsible for sending and receiving data.
 *
 * Communication is done through Unix signal SIGUSR1 and SIGUSR2, where SIGUSR1
 * is equivalent to a 0 bit and SIGUSR2 is equivalent to a 1 bit. Messaging is
 * done 1 bit at a time, until the entire message has beent transferred and
 * received. To avoid pinging a server while it is still occupied handling a
 * signal, each message is followed by a confirmation ping from the receiver.
 */
typedef struct s_server
{
	int			sender;
	bool		state_lock;
	t_e_state	state_current;
	t_e_state	state_previous;
	t_s_message	message_out;
	t_s_message	message_in;
}	t_s_server;

typedef void	(*t_f_handler)(pid_t, siginfo_t *, void *);

#endif
