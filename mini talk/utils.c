/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:21:37 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/15 10:55:21 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	init_str(char **str)
{
	*str = malloc(sizeof(char) * 2);
	if (!*str)
		return (0);
	(*str)[0] = '\0';
	(*str)[1] = '\0';
	return (1);
}

void	handle_end_of_message(char *str)
{
	if (!str)
	{
		return ;
	}
	ft_printf("%s\n", str);
	free(str);
}

void	update_byte(char *byte, int sig, int *i)
{
	if (!byte || !i)
		return ;
	if (sig == SIGUSR1)
		*byte |= (1 << (7 - *i));
	(*i)++;
}

void	add_byte_to_str(char *str, char byte, int *j)
{
	if (!str || !j || *j < 0)
		return ;
	str[*j] = byte;
	str[*j + 1] = '\0';
	(*j)++;
}

void	manage_realloc(char **str, int j)
{
	char	*temp;

	if (!str || !*str || j < 0)
		return ;
	temp = ft_monrealloc(*str, j + 1);
	if (!temp)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	*str = temp;
}
