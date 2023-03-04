/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message_receive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 13:07:03 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_message_receive.h"

#include "e_state.h"
#include "message_last_byte.h"
#include "sig_to_bit.h"
#include "messages.h"
#include "state_restore.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	client_message_receive(pid_t pid, t_s_server *client)
{
	t_s_message	*message;
	bool		bit;

	(void)pid;
	message = &client->message_in;
	bit = *message_last_byte(message) & message->mask;
	if (bit != sig_to_bit(ONE))
	{
		ft_putendl_fd("Server is busy, couldn't send message", STDOUT_FILENO);
		ft_free_all();
		exit(EXIT_FAILURE);
	}
	state_restore(client);
}
