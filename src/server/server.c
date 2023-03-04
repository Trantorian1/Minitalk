/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 13:51:19 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_deny.h"
#include "server_register_listeners.h"
#include "server_is_occupied.h"
#include "server_state.h"
#include "state_set.h"
#include "sig_to_bit.h"
#include "bit_receive.h"
#include "message_full.h"
#include "message_was_received.h"
#include "printpid.h"
#include "e_state.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>

/**
 * @brief Singleton server instance, responsible for receiving and displaying
 * messages received from clients.
 *
 * Server can only receive messages from one client at a time, so clients that
 * try to connect while server is busy will have their connection denied and
 * receive an error code.
 *
 * Server is implemented as a state machine, with 4 main states:
 * - MESSAGE_WAIT: waits for next signal from client (default state).
 * - MESSAGE_SEND: message bit received, sends confirmation signal to client.
 * - MESSAGE_STORE: message buffer full, stores it in string.
 * - MESSAGE_DISPLAY: message complete, displays it.
 */
t_s_server	g_server = {
	.sender = -1,
	.state_lock = true,
	.state_current = MESSAGE_WAIT,
	.state_previous = MESSAGE_WAIT,
	.message_out = {.bit_count = 0, .buffer = "", .str_full = NULL},
	.message_in = {.bit_count = 0, .buffer = "", .str_full = NULL}
};

static void	signal_handler(int sig, siginfo_t *info, void *ptr)
{
	t_s_message	*message;

	(void)ptr;
	if (server_is_occupied(&g_server, info->si_pid))
	{
		bit_deny(info->si_pid);
		return ;
	}
	message = &g_server.message_in;
	bit_receive(sig_to_bit(sig), &g_server);
	g_server.sender = info->si_pid;
	if (message_full(message))
		state_set(&g_server, MESSAGE_STORE);
	else if (message_was_received(message))
		state_set(&g_server, MESSAGE_DISPLAY);
	else
		state_set(&g_server, MESSAGE_SEND);
	g_server.state_lock = false;
}

/**
 * @brief Main server event loop, handles server setup and state machine.
 *
 * @warning Server operates on an infinite loop, so this program will never exit
 * unless shut down manually.
 */
int	main(void)
{
	printpid();
	if (!server_register_listeners(&signal_handler))
	{
		ft_free_all();
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		if (g_server.state_lock)
			continue ;
		server_state(g_server.sender, &g_server);
	}
	return (EXIT_SUCCESS);
}
