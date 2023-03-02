/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_message_display.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:51:22 by                   #+#    #+#             */
/*   Updated: 2023/03/02 11:51:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MESSAGE_DISPLAY_H
# define SERVER_MESSAGE_DISPLAY_H

# include <unistd.h>
# include "s_server.h"

void	server_message_display(pid_t pid, t_s_server *server);

#endif
