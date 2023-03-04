/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_is_occupied.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:12:02 by                   #+#    #+#             */
/*   Updated: 2023/03/04 14:12:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_IS_OCCUPIED_H
# define SERVER_IS_OCCUPIED_H

# include <stdbool.h>
# include <unistd.h>
# include "s_server.h"

bool	server_is_occupied(t_s_server *server, pid_t sender);

#endif
