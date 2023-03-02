/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:05:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 17:08:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printpid.h"

#include "libft.h"
#include <unistd.h>

void	printpid(void)
{
	ft_putstr_fd("PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
