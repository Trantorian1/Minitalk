/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_store.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:24:56 by                   #+#    #+#             */
/*   Updated: 2023/03/02 14:24:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MESSAGE_STORE_H
# define SERVER_MESSAGE_STORE_H

# include <unistd.h>
# include "s_server.h"

void	server_message_store(pid_t pid, t_s_server *server);

#endif
