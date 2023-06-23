/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:10:21 by snocita           #+#    #+#             */
/*   Updated: 2023/06/23 19:26:40 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int check_quotation(char *str)
{
    if (check_quantity_of_quotation(str) == 0)
        return (0);
    if (check_for_letters(str) == 0)
        return (0);
    return (1);
}

int check_quantity_of_quotation(char *str)
{
    int scount;
    int dcount;

    scount = 0;
    dcount = 0;
    while (*str)
    {
        if (*str == '\'')
            scount++;
        if (*str == '\"')
            dcount++;
        str++;
    }
    if ((scount % 2 != 0) || (dcount % 2 != 0))
        return (0);
    return (1);
}

int check_for_letters(char *str)
{
    int found_status;

    found_status = 0;
    while (*str)
    {
        if (*str == '\'' || *str == '\"')
        {
            found_status = 1;
            break;
        }
        str++;
    }
    if (found_status == 1)
        return (0);
    return (1);
}

char *remove_quotes(char *str)
{
    int i;
    int j;
    char *ret_str = malloc(sizeof(char *) * 100);
    if (!ret_str)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == '\"' || str[i] == '\''))
            i++;
        ret_str[j++] = str[i++];
    }
    ret_str[j] = '\0';
    return (ret_str);
}
