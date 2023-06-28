/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/28 16:21:37 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern char	**g_my_envp;

void	free_double_arr(char **str)
{
	char	**temp;

	if (!str)
		return ;
	temp = str;
	while (*str)
	{
		if (*str && (*str != NULL))
			free(*str);
		str++;
	}
	if (temp != NULL)
		free(temp);
	return ;
}

void	free_linked_list(t_cmd *head)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	while (head != NULL)
	{
		tmp = head;
		// if (head->args != NULL)
		// 	free_double_arr(head->args);
		while (head->args[i] && (head->args[i] != NULL))
		{
			if (head->args[i] && (head->args[i] != NULL))
				free(head->args[i]);
			i++;
		}
		free(head->args);
		if (head->cmd != NULL)
			free(head->cmd);
		if (head->flag != NULL)
			free(head->flag);
		head = head->next;
		if (tmp != NULL)
			free(tmp);
	}
}

t_cmd	*malloc_node(void)
{
	t_cmd	*head;

	head = malloc(sizeof(t_cmd));
	if (!head)
		return (NULL);
	head->args = NULL;
	head->flag = NULL;
	head->cmd = NULL;
	head->fd = 0;
	head->next = NULL;
	return (head);
}

// char	*convert_spaces_into_underscore(char *input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i] && input[i] != '\"')
// 		i++;
// 	while (input[i] && input[i] != '\"')
// 	{
// 		if (input[i] == ' ')
// 			input[i] = '_';
// 		i++;
// 	}
// 	return (input);
// }

t_cmd	*create_linked_list(char *input)
{
	char	**program;
	int		i;
	t_cmd	*head;
	t_cmd	*curr;

	i = 0;
	head = NULL;
	debug_get_full_input(input);
	program = ft_split(input, '|');
	while (program[i])
	{
		if (head == NULL)
		{
			head = malloc_node();
			head = lexing(program[i], head);
			curr = head;
		}
		else
		{
			curr->next = malloc_node();
			curr = curr->next;
			curr = lexing(program[i], curr);
		}
		i++;
	}
	free_double_arr(program);
	return (head);
}

void	gate_function(char *input)
{
	t_cmd	*head;

	head = create_linked_list(input);
	free_linked_list(head);
	return ;
}

// from input detectc delimiters and implement a linked list
// accordingly so that each command points to its next
// delimeters -> '|', '>', '>>', '<', '<<'
// echo hello world | wc -l > text.txt
int	main(int ac, char **av, char **envp)
{
	char	*input;

	if (ac != 1)
		return (0);
	ft_debug();
	g_my_envp = obtain_envp(envp);
	printf("\necho -n hello there | cat -n | ls\n");
	input = readline("Minishelly$ ");
	if (strlen(input) > 0)
		add_history(input);
	gate_function(input);
	free_double_arr(g_my_envp);
	free(input);
	return (0);
}
