/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_was_processed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:13:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:38:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_was_processed.h"

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

bool	message_was_processed(t_s_message *message)
{
	size_t	index;

	index = message->bit_count / 8;
	return (index >= SIZE_BUFFER || message->buffer[index] == '\0');
}
