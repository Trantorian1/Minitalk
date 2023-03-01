/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_last_byte.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:26:22 by                   #+#    #+#             */
/*   Updated: 2023/03/01 16:26:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_LAST_BYTE_H
# define MESSAGE_LAST_BYTE_H

# include <stdint.h>
# include "s_message.h"

uint8_t	*message_last_byte(t_s_message *message);

#endif
