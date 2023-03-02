/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:29:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 20:54:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_receive.h"

#include "message_reset.h"
#include "message_full.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void	bit_receive(bool bit, t_s_server *server)
{
	t_s_message	*message;
	size_t		index;

	if (!server)
		return ;
	message = &(server->message_in);
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
