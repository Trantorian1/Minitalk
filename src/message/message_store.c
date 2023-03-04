/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_store.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:05:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 14:06:02 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_store.h"

#include "message_was_processed.h"
#include "message_reset.h"
#include <stddef.h>

/**
 * @brief Stores a string into a message.
 *
 * @param message (t_s_message *): Message to store the string in.
 * @param str (char **): Pointer to the string to store. Will be mutated to
 * point to the last character not stored in the message.
 */
void	message_store(t_s_message *message, char **str)
{
	size_t		i;

	if (!message || !str || !*str)
		return ;
	if (message_was_processed(message))
		message_reset(message);
	i = 0;
	while (i < SIZE_BUFFER - 1 && (*str)[i])
	{
		message->buffer[i] = (*str)[i];
		i++;
	}
	message->buffer[i] = '\0';
	*str += i;
}
