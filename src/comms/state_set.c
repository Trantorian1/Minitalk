/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:26:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 10:47:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_set.h"

void	state_set(t_s_server *server, t_e_state state)
{
	server->state_previous = server->state_current;
	server->state_current = state;
}
