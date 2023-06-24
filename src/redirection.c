/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:03:33 by snocita           #+#    #+#             */
/*   Updated: 2023/06/24 03:02:42 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void redirection_in(char str)
{
	int	fd;

	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		return (ft_putstr_fd("Handling file failed\n", 2));
	dup2(fd, 0);
	close(fd);
}

void redirection_out(char *str)
{
	int		fd;

	fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return (ft_putstr_fd("Filed to handle a file\n", 2));
	dup2(fd, 1);
	close(fd);
}

void double_redirection(char *str)
{
	int		fd;


	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (ft_putstr_fd("Filed to handle a file\n", 2));
	dup2(fd, 1);
	close(fd);
}

void here_doc(char *str)
{
    (void)str;
    printf("hello");
    return;
}
