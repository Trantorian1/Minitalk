/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:00:10 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:39:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_full.h"

#include "libft.h"
#include <unistd.h>

bool	message_full(t_s_message *message)
{
	return (message->bit_count / 8 >= SIZE_BUFFER);
}
