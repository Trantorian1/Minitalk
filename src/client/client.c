/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:31:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 21:02:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_receive.h"
#include "client_state.h"
#include "e_state.h"
#include "message_was_sent.h"
#include "s_server.h"
#include "message_send.h"
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>

static t_s_server	g_client = {
	.sig_count = 0,
	.signal_override = false,
	.state_current = MESSAGE_SEND,
	.state_previous = MESSAGE_SEND,
	.message_out = {.bit_count = 0, .message = NULL},
	.message_in = {.bit_count = 0, .message = NULL}
};

static void	signal_handle(int signal)
{
	bit_receive(signal, &g_client);
}

int	main(int argc, char *argv[])
{
	int32_t		pid;
	char		*message;

	pid = atoi(argv[1]);
	message = argv[2];
	g_client.message_out.message = message;
	if (argc < 3)
		return (EXIT_FAILURE);
	signal(SIGUSR1, &signal_handle);
	signal(SIGUSR2, &signal_handle);
	while (!message_was_sent(&g_client))
	{
		client_state(pid, &g_client);
		pause();
	}
	return (EXIT_SUCCESS);
}
