/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:31:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 13:56:00 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig_to_bit.h"
#include "bit_receive.h"
#include "client_state.h"
#include "message_send.h"
#include "message_store.h"
#include "message_was_processed.h"
#include "message_was_sent.h"
#include "s_server.h"
#include "state_set.h"
#include "e_state.h"
#include "libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Singleton client instance, responsible for sending messages to a
 * server.
 *
 * Client is implemented as a state machine, with 2 main states:
 * - MESSAGE_SEND: sends current message bit to server and waits for
 *   confirmation (default state).
 * - MESSAGE_RECEIVE: receives ping from server. If reception was sucessful,
 *   sends next bit, otherwise exits program. This occurs whenever the server is
 *   busy with another request and cannot process a new message at this time.
 */
t_s_server	g_client = {
	.state_lock = false,
	.state_current = MESSAGE_SEND,
	.state_previous = MESSAGE_SEND,
	.message_out = {.bit_count = 0, .mask = 0x80, .buffer = ""},
	.message_in = {.bit_count = 0, .mask = 0x00, .buffer = ""}
};

static void	signal_handle(int signal)
{
	bit_receive(sig_to_bit(signal), &g_client);
	g_client.state_lock = false;
}

/**
 * @brief Main client event loop, handles client setup and state machine.
 * 
 * @warning Client will keep running until messasge is send or server denies
 * connection, and should not bw interrupted in the mean time.
 */
int	main(int argc, char *argv[])
{
	int32_t		pid;
	char		*str;

	if (argc < 3)
		return (EXIT_FAILURE);
	pid = atoi(argv[1]);
	str = argv[2];
	if (pid == -1)
	{
		ft_free_all();
		exit(EXIT_FAILURE);
	}
	message_store(&g_client.message_out, &str);
	signal(SIGUSR1, &signal_handle);
	signal(SIGUSR2, &signal_handle);
	while (!message_was_sent(&g_client) || *str != '\0')
	{
		if (g_client.state_lock)
			continue ;
		client_state(pid, &g_client);
		if (message_was_sent(&g_client) && *str != '\0')
			message_store(&g_client.message_out, &str);
	}
	return (EXIT_SUCCESS);
}
