/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_store.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:39:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_message_store.h"

#include "message_to_string.h"
#include "state_set.h"
#include "e_state.h"
#include "libft.h"

void	server_message_store(pid_t pid, t_s_server *server)
{
	t_s_message	*message;

	(void)pid;
	if (!server)
		return ;
	message = &server->message_in;
	message_to_string(message);
	state_set(server, MESSAGE_SEND);
	server->state_lock = false;
}
