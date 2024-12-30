/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:54:18 by yann              #+#    #+#             */
/*   Updated: 2024/12/17 10:57:25 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void gestionnaire(int sig)
{
    static int i = 0;
    static char byte = 0;

    if (sig == SIGUSR1)
    {
        byte |= (1 << (7 - i));
    }
    i++;
    if (i == 8)
    {
        write(1, &byte, 1);
        i = 0;
        byte = 0;
    }
}

int main()
{
    struct sigaction sa;

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

    return 0;
}
