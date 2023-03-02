/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_state.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:54:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 14:22:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_STATE_H
# define E_STATE_H

typedef enum e_state
{
	IDLE,
	MESSAGE_SEND,
	MESSAGE_WAIT,
	MESSAGE_STORE,
	MESSAGE_DISPLAY,
	USER_CREATE,
	USER_CHECK,
	USER_NOTIFY,
	CLEANUP,
	E_STATE_SIZE
}	t_e_state;

#endif
