/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_state.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:12:02 by                   #+#    #+#             */
/*   Updated: 2023/03/04 14:12:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_STATE_H
# define CLIENT_STATE_H

# include <unistd.h>
# include "s_server.h"

void	client_state(pid_t pid, t_s_server *client);

#endif
