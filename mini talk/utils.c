/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:21:37 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/07 14:26:22 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_str(char **str)
{
	*str = malloc(2);
	if (*str)
		(*str)[0] = '\0';
}

void	handle_end_of_message(char *str)
{
	ft_printf("%s\n", str);
	free(str);
}

void	update_byte(char *byte, int sig, int *i)
{
	if (sig == SIGUSR1)
		*byte |= (1 << (7 - *i));
	(*i)++;
}

void	add_byte_to_str(char *str, char byte, int *j)
{
	str[*j] = byte;
	str[*j + 1] = '\0';
	(*j)++;
}

void	manage_realloc(char **str, int j)
{
	char *temp = ft_monrealloc(*str, j + 1);
	if (!temp)
	{
		free(*str);
		*str = NULL;
	}
	else
		*str = temp;
}