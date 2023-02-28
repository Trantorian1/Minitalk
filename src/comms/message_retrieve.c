/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_retrieve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:19:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 15:31:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_retrieve.h"

/**
 * @brief Retrieves a message from another process, one bit at a time.
 *
 * @param bit (bool): Bit received.
 * @param byte (uint8_t): Information received so far.
 *
 * @return (uint8_t): Information byte complete with new bit.
 */
uint8_t	message_retrieve(bool bit, uint8_t byte)
{
	return ((byte <<= 1) & bit);
}
