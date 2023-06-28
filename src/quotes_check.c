/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:10:21 by snocita           #+#    #+#             */
/*   Updated: 2023/06/28 15:49:31 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*apply_delete(char *tok, int *i)
{
	char	*tmp[2];
	char	*new_tok;
	char	quote;
	int		j;

	quote = tok[*i];
	j = *i + 1;
	while (tok[j] != quote)
		j++;
	tmp[0] = ft_substr(tok, 0, *i);
	tmp[1] = ft_substr(tok, *i + 1, j - *i - 1);
	new_tok = ft_strjoin(tmp[0], tmp[1]);
	free (tmp[0]);
	free (tmp[1]);
	*i = j - 2;
	tmp[0] = ft_strjoin(new_tok, tok + j + 1);
	free (tok);
	free (new_tok);
	tok = ft_strdup(tmp[0]);
	free (tmp[0]);
	return (tok);
}

char	*delete_quote_tok(char *tok)
{
	int		i;
	char	*new_tok;

	i = 0;
	while (tok[i])
	{
		if (tok[i] == '\'' || tok[i] == '"')
		{
			new_tok = apply_delete(tok, &i);
		}
		i++;
	}
	return (new_tok);
}

//from "hello there" to "hello" "there"
void	remove_quote(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (((cmd[i] && ft_strchr(cmd[i], '\''))
				|| (cmd[i] && ft_strchr(cmd[i], '"'))))
			cmd[i] = delete_quote_tok(cmd[i]);
		i++;
	}
}
