/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_message.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:42:11 by                   #+#    #+#             */
/*   Updated: 2023/02/28 20:42:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MESSAGE_H
# define CLIENT_MESSAGE_H

# include <unistd.h>
# include "s_server.h"

void	client_message(pid_t pid, t_s_server *client);

#endif
