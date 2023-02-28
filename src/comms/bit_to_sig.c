/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_to_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:14:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 15:17:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bit_to_sig.h"

#include "messages.h"
#include <stdbool.h>

int	bit_to_sig(bool bit)
{
	if (bit)
		return (ONE);
	else
		return (0);
}
