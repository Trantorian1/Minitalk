/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_send.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:59:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 20:12:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_send.h"

#include "messages.h"
#include "bit_to_sig.h"
#include "s_server.h"
#include <stdint.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>

/**
 * @brief Sends a message to another process, one bit at a time.
 *
 * @param pid (pid_t): PID of the process to send the message to.
 * @param server (t_s_server *): Server sending the message.
 */
void	message_send(pid_t pid, t_s_server *server)
{

}