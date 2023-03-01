/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message_send.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:59:35 by                   #+#    #+#             */
/*   Updated: 2023/03/01 15:59:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MESSAGE_SEND_H
# define CLIENT_MESSAGE_SEND_H

# include <unistd.h>
# include "s_server.h"

void	client_message_send(pid_t pid, t_s_server *client);

#endif
