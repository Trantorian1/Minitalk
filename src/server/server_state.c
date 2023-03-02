/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:11:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 11:54:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_state.h"

#include "do_nothing.h"
#include "server_message_send.h"
#include "server_message_display.h"

typedef void				(*t_state_func)(pid_t, t_s_server *);

static const t_state_func	g_states[E_STATE_SIZE] = {
	&do_nothing,
	&server_message_send,
	&do_nothing,
	&server_message_display,
	&do_nothing,
	&do_nothing,
	&do_nothing,
};

void	server_state(pid_t pid, t_s_server *client)
{
	g_states[client->state_current](pid, client);
}
