/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:55:47 by snocita           #+#    #+#             */
/*   Updated: 2023/06/23 21:46:51 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <fcntl.h>

static int fd;

void debug_write(char *str, int id)
{
    int i = 1;
    if ((id == 1) && (ft_strlen(str) == 0))
    {
        write(fd, ft_itoa(i), 1);
        i++;
        write(fd, ") START NEW NODE", ft_strlen(") START NEW NODE"));
    }
    else
        write(fd, str, ft_strlen(str));
}

void ft_debug(void)
{
    fd = open("src/debugging.txt", O_WRONLY);
    if (fd == -1)
    {
        printf("FD BROKEN\n");
        return;
    }
    return;
}