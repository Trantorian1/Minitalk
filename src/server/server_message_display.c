/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:50:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 11:53:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_message_display.h"

#include "message_reset.h"
#include "state_set.h"
#include "libft.h"
#include <signal.h>
#include <unistd.h>

void	server_message_display(pid_t pid, t_s_server *server)
{
	(void)pid;
	ft_putendl_fd(server->message_in.buffer, STDOUT_FILENO);
	message_reset(&server->message_in);
	state_set(server, MESSAGE_WAIT);
	server->state_lock = true;
}
