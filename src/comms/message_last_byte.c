/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_last_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:25:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 16:46:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_last_byte.h"

#include <stdint.h>
#include <stddef.h>

uint8_t	*message_last_byte(t_s_message *message)
{
	size_t	index;

	index = (message->bit_count - 1) / 8;
	return ((uint8_t *)&message->buffer[index]);
}
