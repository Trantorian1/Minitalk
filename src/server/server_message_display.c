/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:50:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 13:01:03 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_message_display.h"

#include "message_to_string.h"
#include "message_reset.h"
#include "state_set.h"
#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	server_message_display(pid_t pid, t_s_server *server)
{
	t_s_message	*message;

	(void)pid;
	if (!server)
		return ;
	message = &server->message_in;
	if (!message->str_full)
		ft_putendl_fd(message->buffer, STDOUT_FILENO);
	else
	{
		ft_putendl_fd(message_to_string(message), STDOUT_FILENO);
		ft_free(message->str_full);
		message->str_full = NULL;
	}
	message_reset(&server->message_in);
	state_set(server, MESSAGE_WAIT);
	server->sender = -1;
	server->state_lock = true;
}
