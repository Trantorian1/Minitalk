/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:57:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 16:07:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_H
# define S_MESSAGE_H

# include <stdint.h>

# define SIZE_BUFFER 256

typedef struct s_message
{
	uint8_t		mask;
	uint32_t	bit_count;
	char		buffer[SIZE_BUFFER];
}	t_s_message;

#endif
