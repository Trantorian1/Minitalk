/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 17:08:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_register_listeners.h"
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

t_s_server	g_server = {
	.sender = 0,
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
