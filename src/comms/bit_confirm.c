/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_confirm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:14:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 10:22:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_confirm.h"

#include "messages.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	bit_confirm(pid_t pid)
{
	kill(pid, ONE);
}
