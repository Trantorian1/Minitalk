/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 16:00:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_state.h"

#include "client_message_send.h"
#include "client_message_receive.h"
#include "do_nothing.h"
#include <stdio.h>
#include <unistd.h>

typedef void				(*t_state_func)(pid_t, t_s_server *);

static const t_state_func	g_states[E_STATE_SIZE] = {
	&do_nothing,
	&client_message_send,
	&client_message_receive,
	&do_nothing,
	&do_nothing,
	&do_nothing,
	&do_nothing,
};

void	client_state(pid_t pid, t_s_server *client)
{
	g_states[client->state_current](pid, client);
}
