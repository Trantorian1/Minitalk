/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_last_byte.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:12:02 by                   #+#    #+#             */
/*   Updated: 2023/03/04 14:12:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_LAST_BYTE_H
# define MESSAGE_LAST_BYTE_H

# include <stdint.h>
# include "s_message.h"

uint8_t	*message_last_byte(t_s_message *message);

#endif
