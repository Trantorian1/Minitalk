/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:19:22 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 20:41:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_message.h"

#include "e_state.h"
#include "bit_send.h"
#include <stdbool.h>

void	client_message(pid_t pid, t_s_server *client)
{
	bit_send(pid, client);
}
