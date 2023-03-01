/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message_send.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:58:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 15:59:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_message_send.h"

#include "bit_send.h"

void	client_message_send(pid_t pid, t_s_server *client)
{
	bit_send(pid, client);
	client->signal_override = false;
}
