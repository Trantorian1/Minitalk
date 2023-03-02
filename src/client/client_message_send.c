/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message_send.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:58:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 15:13:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_message_send.h"

#include "bit_send.h"
#include "libft.h"
#include <unistd.h>

void	client_message_send(pid_t pid, t_s_server *client)
{
	client->state_lock = true;
	bit_send(pid, client);
}
