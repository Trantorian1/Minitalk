/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:20:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 17:12:16 by emcnab           ###   ########.fr       */
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
	if (message->mask == 0)
		message->mask = 0x80;
	index = message->bit_count / 8;
	bit = message->buffer[index] & message->mask;
	message->mask >>= 1;
	message->bit_count++;
	printf("current character is %c\n", message->buffer[index]);
	printf("sending bit %d to PID %d\n", bit, pid);
	printf("sending mask is now %hhu\n", message->mask);
	kill(pid, bit_to_sig(bit));
	server->state_previous = server->state_current;
	server->state_current = MESSAGE_WAIT;
}
