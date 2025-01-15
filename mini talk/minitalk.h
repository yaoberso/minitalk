/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:44:30 by yaoberso          #+#    #+#             */
/*   Updated: 2025/01/15 11:31:08 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_process
{
	char	**str;
	char	byte;
	int		*j;
	int		*i;
	char	*byte_ref;
}			t_process;
int			init_str(char **str);
void		handle_end_of_message(char *str);
void		update_byte(char *byte, int sig, int *i);
void		add_byte_to_str(char *str, char byte, int *j);
void		manage_realloc(char **str, int j);
char		*ft_monrealloc(char *str, int new_size);

#endif
