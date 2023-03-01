/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:11:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 13:12:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_reset.h"
#include <stdint.h>

void	message_reset(t_s_message *message)
{
	message->mask = (int8_t)0x80;
	message->bit_count = 0;
}
