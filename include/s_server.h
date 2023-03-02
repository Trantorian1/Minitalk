/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_server.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:39:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 11:21:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SERVER_H
# define S_SERVER_H

# include "e_state.h"
# include "s_message.h"
# include <stdint.h>
# include <stdbool.h>

typedef struct s_server
{
	int			sender;
	bool		state_lock;
	t_e_state	state_current;
	t_e_state	state_previous;
	t_s_message	message_out;
	t_s_message	message_in;
}	t_s_server;

#endif
