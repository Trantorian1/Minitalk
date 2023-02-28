/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:34:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 19:43:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_retrieve.h"
#include "s_server.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>

static t_s_server	g_server = {.byte = 0, .sig_count = 0};

static void	signal_handler(int32_t bit)
{
	printf("signal received!\n");
	g_server.byte = message_retrieve(bit, g_server.byte);
	g_server.sig_count = (g_server.sig_count + 1) % 9;
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (g_server.sig_count != 8)
		pause();
	printf("%c\n", (char)g_server.byte);
}
