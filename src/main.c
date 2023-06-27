/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/27 19:50:45 by snocita          ###   ########.fr       */
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
		free(*str);
		str++;
	}
	free(temp);
}

void	free_linked_list(t_cmd *head)
{
	t_cmd	*tmp;

	while (head != NULL)
	{
		tmp = head;
		printf("!!hello\n");
		if (head->args)
			free_double_arr(head->args);
		free(head->cmd);
		free(head->flag);
		head = head->next;
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
	if (ac != 1)
		return (0);
	char	*input;
	ft_debug();
	g_my_envp = obtain_envp(envp, ac, av);
	printf("\necho -n hello there | cat -n | ls\n");
	input = readline("Minishelly$ ");
	if (strlen(input) > 0)
		add_history(input);
	gate_function(input);
	// printf("%p\n", input);
	free_double_arr(g_my_envp);
	free(input);
	return (0);
}
