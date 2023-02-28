/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_send.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:59:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 15:29:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_send.h"

#include "messages.h"
#include "bit_to_sig.h"
#include <stdint.h>
#include <stdbool.h>
#include <signal.h>

/**
 * @brief Sends a message to another process, one bit at a time.
 *
 * @param pid (pid_t): PID of the process to send the message to.
 * @param message (const char *): message to send to the process.
 */
void	message_send(pid_t pid, const char *message)
{
	size_t		index;
	uint8_t		mask;
	bool		bit;

	index = (size_t)(-1);
	while (message[++index])
	{
		mask = 0x80;
		while (mask > 0)
		{
			bit = mask & message[index];
			mask >>= 1;
			kill(pid, bit_to_sig(bit));
		}
	}
}
