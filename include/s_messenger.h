/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_messenger.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:48:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 19:56:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSENGER_H
# define S_MESSENGER_H

# include "e_state.h"
# include <stdint.h>

typedef struct s_client
{
	const char	*message;
	int8_t		sent;
	t_e_state	state;
}	t_s_client;

#endif
