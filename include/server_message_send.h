/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_send.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:14:39 by                   #+#    #+#             */
/*   Updated: 2023/03/02 11:14:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MESSAGE_SEND_H
# define SERVER_MESSAGE_SEND_H

# include <unistd.h>
# include "s_server.h"

void	server_message_send(pid_t pid, t_s_server *server);

#endif
