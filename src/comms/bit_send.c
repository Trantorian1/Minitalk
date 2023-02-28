/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:20:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 20:37:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_send.h"

#include "bit_to_sig.h"
#include "e_state.h"
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void	bit_send(pid_t pid, t_s_server *server)
{
	t_s_message	*message;
	size_t		index;
	bool		bit;

	if (!server)
		return ;
	message = &server->message_out;
	index = message->bit_count / 8;
	bit = message->message[index] & message->mask;
	message->mask >>= 1;
	message->bit_count++;
	printf("sending bit %d to PID %d\n", bit, pid);
	kill(pid, bit_to_sig(bit));
	server->state_previous = server->state_current;
	server->state_current = MESSAGE_WAIT;
}
