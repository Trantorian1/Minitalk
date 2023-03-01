/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_was_received.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:33:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 16:47:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_was_received.h"

#include "message_last_byte.h"

bool	message_was_received(t_s_message *message)
{
	uint32_t	bit_count;
	bool		is_valid_bit_count;

	bit_count = message->bit_count;
	is_valid_bit_count = ((bit_count != 0) && (bit_count % 8 == 0));
	return (is_valid_bit_count && *message_last_byte(message) == '\0');
}
