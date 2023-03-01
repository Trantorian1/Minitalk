/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 15:43:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_receive.h"
#include "bit_confirm.h"
#include "messages.h"
#include "s_server.h"
#include "libft.h"
#include "sig_to_bit.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>

t_s_server	g_server = {
	.sig_count = 0,
	.signal_override = false,
	.state_current = MESSAGE_SEND,
	.state_previous = MESSAGE_SEND,
	.message_out = {.bit_count = 0, .buffer = ""},
	.message_in = {.bit_count = 0, .buffer = ""}
};

static void	signal_handler(int sig, siginfo_t *info, void *ptr)
{
	(void)ptr;
	printf("received bit %d from PID %d\n", sig_to_bit(sig), info->si_pid);
	bit_receive(sig_to_bit(sig), &g_server);
	bit_confirm(info->si_pid);
}

int	main(void)
{
	struct sigaction	act;

	printf("PID: %d\n", getpid());
	act.sa_sigaction = signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);

	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_free_all();
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_free_all();
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		pause();
	}
}
