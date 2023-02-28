/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_server.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:39:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/28 15:48:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SERVER_H
# define S_SERVER_H

# include <stdint.h>

typedef struct s_server
{
	uint8_t	byte;
	uint8_t	sig_count;
}	t_s_server;

#endif
