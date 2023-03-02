/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message_receive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 11:04:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_message_receive.h"

#include "e_state.h"
#include "message_last_byte.h"
#include "sig_to_bit.h"
#include "messages.h"
#include "state_restore.h"
#include <stdio.h>

void	client_message_receive(pid_t pid, t_s_server *client)
{
	t_s_message	*message;
	bool		bit;

	(void)pid;
	message = &client->message_in;
	bit = *message_last_byte(message) & message->mask;
	if (bit != sig_to_bit(ONE))
		return ;
	state_restore(client);
}
