/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:54:18 by yann              #+#    #+#             */
/*   Updated: 2025/01/07 14:28:02 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static char	*ft_monrealloc(char *str, int new_size)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc(sizeof(char) * (new_size + 1));
	if (newstr == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[new_size] = '\0';
	free(str);
	return (newstr);
}

void	gestionnaire(int sig)
{
	char		*temp;
	static int	j = 0;
	static char	*str = NULL;
	static int	i = 0;
	static char	byte = 0;

	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		if (str == NULL)
			return ;
		str[0] = '\0';
	}
	if (sig == SIGUSR1)
		byte |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (byte == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			j = 0;
			i = 0;
			byte = 0;
			return ;
		}
		else
		{
			str[j] = byte;
			str[j + 1] = '\0';
			j++;
			temp = ft_monrealloc(str, j + 1);
			if (temp == NULL)
			{
				free(str);
				str = NULL;
				return ;
			}
			str = temp;
		}
		i = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = gestionnaire;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("pid du serveur : %i\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}