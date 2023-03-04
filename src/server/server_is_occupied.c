/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_is_occupied.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:01:29 by eliot             #+#    #+#             */
/*   Updated: 2023/03/04 13:02:41 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_is_occupied.h"

bool	server_is_occupied(t_s_server *server, pid_t sender)
{
	return (server->sender != -1 && server->sender != sender);
}
