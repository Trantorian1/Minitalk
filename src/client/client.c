/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:31:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 15:34:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_send.h"
#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

int	main(int argc, const char *argv[])
{
	int32_t		pid;
	const char	*message;

	if (argc != 3)
		return (EXIT_FAILURE);
	pid = atoi(argv[1]);
	message = argv[2];
	message_send(pid, message);
	return (EXIT_SUCCESS);
}
