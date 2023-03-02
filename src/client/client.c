/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:31:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 10:45:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_s_server	g_client = {
	.state_lock = false,
	.state_current = MESSAGE_SEND,
	.state_previous = MESSAGE_SEND,
	.message_out = {.bit_count = 0, .mask = 0x80, .buffer = ""},
	.message_in = {.bit_count = 0, .mask = 0x00, .buffer = ""}
};

static void	signal_handle(int signal)
{
	bit_receive(signal, &g_client);
	g_client.state_lock = false;
}

int	main(int argc, char *argv[])
{
	int32_t		pid;
	char		*str;

	if (argc < 3)
		return (EXIT_FAILURE);
	pid = atoi(argv[1]);
	str = argv[2];
	message_store(&g_client.message_out, &str);
	signal(SIGUSR1, &signal_handle);
	signal(SIGUSR2, &signal_handle);
	while (!message_was_sent(&g_client))
	{
		if (g_client.state_lock)
			continue ;
		client_state(pid, &g_client);
	}
	return (EXIT_SUCCESS);
}
