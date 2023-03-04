/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:57:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/04 14:08:07 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_H
# define S_MESSAGE_H

# include <stddef.h>
# include <stdint.h>

# define SIZE_BUFFER 1024

/**
 * @brief Message buffer containing a collection of bits.
 *
 * Can either be used to stored bits received or bits to send.
 */
typedef struct s_message
{
	uint8_t		mask;
	size_t		bit_count;
	char		buffer[SIZE_BUFFER];
	char		*str_full;
}	t_s_message;

#endif
