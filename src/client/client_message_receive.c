/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message_receive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 16:21:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_message_receive.h"

#include "sig_to_bit.h"
#include "messages.h"
#include <stdio.h>

void	client_message_receive(pid_t pid, t_s_server *client)
{
	t_s_message	*message;
	size_t		index;
	bool		bit;

	(void)pid;
	message = &client->message_in;
	index = (message->bit_count - 1) / 8;
	bit = message->buffer[index] & message->mask;
	printf("confirmation bit as index %zu is %d\n", index, bit);
	if (bit != sig_to_bit(ONE))
		return ;
	client->state_current = client->state_previous;
	client->signal_override = true;
}
