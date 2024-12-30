/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:44:12 by yann              #+#    #+#             */
/*   Updated: 2024/12/17 10:51:02 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	r = 0;
	int	s = 1;
	int	i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		   str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}

	return (s * r);
}

void envoyer_bit(int pid, char bit)
{
    if (bit == '1')
    {
        if (kill(pid, SIGUSR1) == -1)
        {
            ft_printf("Erreur lors de l'envoi du signal SIGUSR1\n");
            exit(1);
        }
    }
    else if (bit == '0')
    {
        if (kill(pid, SIGUSR2) == -1)
        {
            ft_printf("Erreur lors de l'envoi du signal SIGUSR2\n");
            exit(1);
        }
    }
	usleep(100);
}

void envoyer_message(int pid, char *message)
{
    int i = 0;
    int j;
    char bit;

    while (message[i] != '\0')
    {
        j = 7;
        while (j >= 0)
        {

            if ((message[i] >> j) & 1)
                bit = '1';
            else
                bit = '0';
            envoyer_bit(pid, bit);
            j--;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "Usage: ./client <PID_du_serveur> <message>\n", 42);
        return 1;
    }

    int pid = ft_atoi(argv[1]);
    char *message = argv[2];

    envoyer_message(pid, message);

    return 0;
}
