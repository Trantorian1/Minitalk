/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:20:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 14:02:58 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_send.h"

#include "bit_to_sig.h"
#include "e_state.h"
#include "state_set.h"
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Sends the next bit in a message to a server.
 *
 * @param receiver (pid_t): The PID of the server receiving the message.
 * @param sender (t_s_server *): the server sending the message.
 */
void	bit_send(pid_t receiver, t_s_server *sender)
{
	t_s_message	*message;
	size_t		index;
	bool		bit;

	if (!sender)
		return ;
	message = &sender->message_out;
	if (message->mask == 0)
		message->mask = 0x80;
	index = message->bit_count / 8;
	bit = message->buffer[index] & message->mask;
	message->mask >>= 1;
	message->bit_count++;
	state_set(sender, MESSAGE_WAIT);
	kill(receiver, bit_to_sig(bit));
}
