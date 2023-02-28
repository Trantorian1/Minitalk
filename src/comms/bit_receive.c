/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:29:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 20:38:48 by emcnab           ###   ########.fr       */
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
	t_e_state	tmp;

	if (!server)
		return ;
	message = &server->message_in;
	index = message->bit_count / 8;
	message->message[index] <<= 1;
	message->message[index] &= bit;
	message->bit_count++;
	printf("received bit %d, message is now %c\n", bit, message->message[index]);
	if (message->bit_count % 8 == 0)
	{
		tmp = server->state_previous;
		server->state_previous = server->state_current;
		server->state_current = tmp;
	}
}
