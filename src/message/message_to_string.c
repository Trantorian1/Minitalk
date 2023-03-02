/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:09:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 15:22:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_to_string.h"

#include "message_reset.h"
#include "libft.h"

const char	*message_to_string(t_s_message *message)
{
	size_t	char_count;
	char	*str_full;
	char	*tmp;

	char_count = message->bit_count / 8;
	if (char_count == 0)
		return (message->str_full);
	str_full = ft_malloc((char_count + 1) * sizeof(*str_full));
	str_full[char_count] = '\0';
	ft_memcpy(str_full, message->buffer, char_count * sizeof(*str_full));
	if (message->str_full)
	{
		tmp = str_full;
		str_full = ft_strjoin(message->str_full, str_full);
		ft_free(tmp);
		ft_free(message->str_full);
	}
	message->str_full = str_full;
	message_reset(message);
	return (str_full);
}
