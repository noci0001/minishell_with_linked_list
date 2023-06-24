/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:42:42 by snocita           #+#    #+#             */
/*   Updated: 2023/06/24 15:56:15 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

// char	*g_cmd_list[] = {"ls", "cmd", "pwd", "mkdir", "rm", "cp", "mv"};

// MINISHELL NAME
#define MINISHELL_NAME "\033[32mMinishelly\033[0m"

// KEYS
// Single Quote (39)
#define SQUOTE 42
// Double Quote (34)
#define DQUOTE 43

// LIBFT
#include "libft/libft.h"
// # include "libreadline.h"
#include <readline/readline.h>
#include <readline/history.h>
// readline, rl_clear_history, rl_on_new_line,
//	rl_replace_line, rl_redisplay, add_history
#include <stdio.h>
// printf
#include <stdlib.h>
// malloc, free
#include <unistd.h>
// write, access, open, read, close,
//	dup, dup2, pipe, isatty, ttyname,
//	ttyslot, ioctl
#include <sys/types.h>
// fork, wait, waitpid, wait3, wait4
#include <signal.h>
// kill, exit
#include <sys/stat.h>
// getcwd, chdir, stat, lstat, fstat, unlink,
// errono macro
#include <errno.h>
//	execve
#include <dirent.h>
// opendir, readdir, closedir
#include <string.h>
// strerror, perror
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <fcntl.h>
// tcsetattr, tcgetattr, tgetent,
//	tgetflag, tgetnum, tgetstr, tgoto, tputs: termios.h
typedef struct s_cmd t_cmd;

struct s_cmd
{
	char *cmd;
	char *flag;
	char **args;
	int fd[2];
	struct s_cmd *next;
};

typedef struct s_valid
{
	int spaces;
	int path;
	char *env;
	char **splitted_env;
	char *tmp1;
	char *tmp2;
} t_valid;

void create_linked_list(char *input);
t_cmd *malloc_node(void);
void free_double_arr(char **str);
t_cmd *lexing(char *block, t_cmd *curr);
int check_quantity_of_quotation(char *str);
int check_quotation(char *str);
int check_redirection_arg(char *word, int redirection);
int is_red(char *str);
void redirection_in(char *str);
void redirection_out(char *str);
void here_doc(char *str);
void double_redirection(char *str);
int check_for_letters(char *str);
char *remove_quotes(char *str);

#endif