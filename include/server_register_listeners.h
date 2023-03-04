/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_register_listeners.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:12:02 by                   #+#    #+#             */
/*   Updated: 2023/03/04 14:15:33 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_REGISTER_LISTENERS_H
# define SERVER_REGISTER_LISTENERS_H

# include <stdbool.h>
# include "s_server.h"

bool	server_register_listeners(t_f_handler handler);

#endif
