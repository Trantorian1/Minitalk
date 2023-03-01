/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:29:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 16:22:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_receive.h"

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
	if (message->mask == 0x80)
		message->mask = 0x00;
	index = message->bit_count / 8;
	message->buffer[index] <<= 1;
	message->buffer[index] |= bit;
	message->bit_count++;
	printf("stored bit %d, message is now %d\n", bit, message->buffer[index]);
	if (message->bit_count % 8 == 1)
		message->mask = 0x01;
	else
		message->mask <<= 1;
	printf("receiving mask is now %hhu\n", message->mask);
}
