/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_was_sent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:56:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 11:07:44 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_was_sent.h"

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool	message_was_sent(t_s_server *server)
{
	size_t	index;
	size_t	target;

	index = server->message_out.bit_count / 8;
	target = ft_strlen(server->message_out.buffer) + 1;
	return (index == target);
}
