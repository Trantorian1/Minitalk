/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_receive.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:51:08 by                   #+#    #+#             */
/*   Updated: 2023/02/28 20:51:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_RECEIVE_H
# define CLIENT_RECEIVE_H

# include <unistd.h>
# include "s_server.h"

void	client_receive(pid_t pid, t_s_server *client);

#endif
