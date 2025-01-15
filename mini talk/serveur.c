/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:54:18 by yann              #+#    #+#             */
/*   Updated: 2025/01/15 11:53:10 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_monrealloc(char *str, int new_size)
{
	char	*newstr;
	int		i;

	if (!str)
		return (NULL);
	if (new_size <= 0)
	{
		free(str);
		return (NULL);
	}
	newstr = malloc(sizeof(char) * (new_size + 1));
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && i < new_size)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	return (newstr);
}

void	process_byte(t_process *p)
{
	if (p->byte == '\0')
	{
		handle_end_of_message(*p->str);
		*p->str = NULL;
		*p->j = 0;
		*p->i = 0;
		*p->byte_ref = 0;
		return ;
	}
	add_byte_to_str(*p->str, p->byte, p->j);
	manage_realloc(p->str, *p->j);
	*p->i = 0;
	*p->byte_ref = 0;
}

void	gestionnaire(int sig)
{
	t_process		p;
	static int		j = 0;
	static int		i = 0;
	static char		*str = NULL;
	static char		byte = 0;

	if (!str && !init_str(&str))
		return ;
	update_byte(&byte, sig, &i);
	if (i == 8)
	{
		p.str = &str;
		p.byte = byte;
		p.j = &j;
		p.i = &i;
		p.byte_ref = &byte;
		process_byte(&p);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = gestionnaire;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("pid du serveur : %i\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
