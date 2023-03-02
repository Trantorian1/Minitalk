/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_send.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:14:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 13:25:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_message_send.h"

#include "bit_confirm.h"
#include "e_state.h"
#include "state_set.h"
#include <unistd.h>

void	server_message_send(pid_t pid, t_s_server *server)
{
	server->state_lock = true;
	state_set(server, MESSAGE_WAIT);
	bit_confirm(pid);
}
