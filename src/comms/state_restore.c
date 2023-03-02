/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_restore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:33:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 10:35:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_restore.h"
#include "e_state.h"

void	state_restore(t_s_server *server)
{
	t_e_state	tmp;

	tmp = server->state_current;
	server->state_current = server->state_previous;
	server->state_previous = tmp;
}
