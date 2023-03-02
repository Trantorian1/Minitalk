/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:57:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 14:12:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_H
# define S_MESSAGE_H

# include <stddef.h>
# include <stdint.h>

# define SIZE_BUFFER 1024

typedef struct s_message
{
	uint8_t		mask;
	size_t		bit_count;
	char		buffer[SIZE_BUFFER];
	char		*str_full;
}	t_s_message;

#endif
