/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:29:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 10:20:53 by emcnab           ###   ########.fr       */
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
	index = message->bit_count / 8;
	message->buffer[index] <<= 1;
	message->buffer[index] |= bit;
	message->bit_count++;
	if (message->bit_count % 8 == 1)
		message->mask = 0x01;
	else
		message->mask <<= 1;
}
