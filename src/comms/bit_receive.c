/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:29:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 14:04:26 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_receive.h"

#include "message_reset.h"
#include "message_full.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Receives a bit from a server.
 *
 * @param bit (bool): Bit being received.
 * @param receiver (t_s_server *): Server receiving the bit.
 */
void	bit_receive(bool bit, t_s_server *receiver)
{
	t_s_message	*message;
	size_t		index;

	if (!receiver)
		return ;
	message = &(receiver->message_in);
	if (message_full(message))
		message_reset(message);
	index = message->bit_count / 8;
	message->buffer[index] <<= 1;
	message->buffer[index] |= bit;
	message->bit_count++;
	if (message->bit_count % 8 == 1)
		message->mask = 0x01;
	else
		message->mask <<= 1;
}
