/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_register_listeners.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:43:13 by                   #+#    #+#             */
/*   Updated: 2023/03/02 11:44:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_REGISTER_LISTENERS_H
# define SERVER_REGISTER_LISTENERS_H

# include <stdbool.h>
# include <signal.h>

typedef void	(*t_f_handler)(pid_t pid, siginfo_t *info, void *ptr);

bool	server_register_listeners(t_f_handler handler);

#endif
