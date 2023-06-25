/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/24 22:48:12 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void free_double_arr(char **str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return ;
}

void	free_linked_list(t_cmd *head)
{
	t_cmd	*tmp;

	while (head != NULL)
	{
		tmp = head;
		if (head->args)
			free_double_arr(head->args);
		free(head->cmd);
		free(head->flag);
		head = head->next;
		free(tmp);
		tmp = NULL;
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
	// debug_get_full_input(input);
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
	// debug_write("\nCLOSING...", 2);
	free_double_arr(program);
	return (head);
}


void	gate_function(char *input)
{
	if (check_quotation(input) != 1)
		return ;
	t_cmd *head = create_linked_list(input);
	print_linked(head);
	free_linked_list(head);
	return ;
}

// from input detectc delimiters and implement a linked list
// accordingly so that each command points to its next
// delimeters -> '|', '>', '>>', '<', '<<'
// echo hello world | wc -l > text.txt
// "echo hello world wc -l > text.txt";
int main (void)
{
	char	*input;
	// ft_debug();

	printf("\necho -n hello there | cat -n | ls\n");
	input = readline("Minishelly$ ");
	if (strlen(input) > 0)
		add_history(input);
	gate_function(input);
	free(input);
	return (0);
}
