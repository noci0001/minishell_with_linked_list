/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:55:47 by snocita           #+#    #+#             */
/*   Updated: 2023/06/26 16:41:54 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <fcntl.h>
#include <time.h>

static int fd;
#define HEADER "             ✨-----------🐚 🐚 🐚-------------------------✨\n             ✨ Start of MINISHELL      Debugging Session ✨\n             ✨---------- 🐚 🐚 🐚 ------------------------✨\n"

void	debug_write(char *str, int id)
{
	int		i = 0;
	char	ch;

	if (ft_strlen(str) == 0)
		return ;
	if (id == 0)
	{
		while (str[i])
		{
			ch = str[i];
			write(fd, &ch, 1);
			i++;
		}
	}
	if (id == 1)
	{
		while (str[i])
		{
			ch = str[i];
			write(fd, &ch, 1);
			i++;
		}
		write(fd, "\n", 1);
	}
	if (id == 2)
	{
		while (str[i])
		{
			ch = str[i];
			write(fd, &ch, 1);
			i++;
		}
		write(fd, "\n", 1);
		close(fd);
	}
	return ;
}

char	*get_time(void)
{
	time_t currentTime;
	char *timeString;

	currentTime = time(NULL);
	timeString = ctime(&currentTime);
	return (timeString);
}

void	create_header()
{
	debug_write("\n\n", 0);
	debug_write(get_time(), 1);
	debug_write(HEADER, 1);
	debug_write("\n\n", 0);
	return ;
}

void	debug_get_full_input(char *str)
{
	debug_write("Intercepted input:", 1);
	debug_write("\t\t", 0);
	debug_write(str, 1);
	debug_write("\n", 1);
}

void	debug_get_sectioned_input(char *str)
{
	debug_write("Sectioned input:", 1);
	debug_write("\t\t", 0);
	debug_write(str, 1);
}

void	ft_debug(void)
{
	fd = open("src/debugging.txt", O_WRONLY);
	if (fd == -1)
	{
		printf("FD BROKEN\n");
		return ;
	}
	create_header();
	return ;
}

void	print_linked(t_cmd *head)
{
	int i;
	t_cmd *temp;

	temp = head;
	while (temp)
	{
		printf("cmd: %s\n", temp->cmd);
		if (temp->flag)
			printf("flag: %s\n", temp->flag);
		i = 0;
		while (temp->args && temp->args[i])
		{
			printf("args %s\n", temp->args[i]);
			i++;
		}
		temp = temp->next;
	}
}
