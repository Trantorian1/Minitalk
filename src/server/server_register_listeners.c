/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_register_listeners.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:40:15 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 11:47:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_register_listeners.h"

#include <stdlib.h>

bool	server_register_listeners(t_f_handler handler)
{
	struct sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		return (false);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		return (false);
	return (true);
}
