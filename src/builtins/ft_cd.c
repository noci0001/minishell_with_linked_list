/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:43:04 by snocita           #+#    #+#             */
/*   Updated: 2023/06/27 18:35:42 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**g_my_envp;

int	check_nb_args(char **args)
{
	if (args[0] == NULL)
		return (0);
	if (args[1] != NULL)
		return (0);
	return (1);
}

// static void	set_oldpwd(char *oldpwd, t_env *env)
// {
// 	char	*tmp;
// 	t_env	*pwdsearch;

// 	pwdsearch = ft_envlst_search(env, "OLDPWD");
// 	if (pwdsearch)
// 		ft_envlst_clearone(&env, pwdsearch);
// 	if (oldpwd)
// 	{
// 		tmp = ft_strjoin("OLDPWD=", oldpwd);
// 		free(oldpwd);
// 		ft_envlstadd_back(&env, ft_envlst_new(tmp));
// 		free(tmp);
// 	}
// 	else
// 		ft_envlstadd_back(&env, ft_envlst_new("OLDPWD"));
// }

// static void	set_error(char *args, char *old_pwd)
// {
// 	g_exit_status = 1;
// 	free(old_pwd);
// 	ft_dprintf(2, "minishell: cd: ");
// 	perror (args);
// }

void	update_envp(char **g_my_envp, char *new_pwd)
{
	int		i;
	char	*pwd_prefix;
	char	*tmp;

	i = 0;
	while (ft_strncmp(g_my_envp[i], "PWD=", ft_strlen("PWD=")))
		i++;
	free(g_my_envp[i]);
	pwd_prefix = ft_strdup("PWD=");
	tmp = ft_strdup(new_pwd);
	g_my_envp[i] = ft_strjoin(pwd_prefix, tmp);
	free(tmp);
	free(pwd_prefix);
	return ;
}

void	ft_cd(t_cmd	*input_struct, char **g_my_envp)
{
	char	pwd[4097];
	char	*cwd;
	char	*beforesearch;
	char	*oldpwd;
	char	*pwdsearch;

	(void)g_my_envp;
	if (check_nb_args(input_struct->args) == 0)
	{
		printf("Too many args\n");
		return ;
	}
	beforesearch = ft_get_env(g_my_envp, "PWD=");
	oldpwd = NULL;
	if (beforesearch)
		oldpwd = ft_strdup(beforesearch);
	if (!chdir(input_struct->args[0]))
	{
		cwd = getcwd(pwd, 4096);
		update_envp(g_my_envp, cwd);
		pwdsearch = ft_get_env(g_my_envp, "PWD=");
	}
	free(oldpwd);
	return ;
}

//args == ".." "." "../desktop"
// void	ft_cd(char **args, t_env *env)
// {
// 	char	pwd[4097];
// 	char	*oldpwd;
// 	t_env	*pwdsearch;
// 	t_env	*beforesearch;
// 	char	*tmp;

// 	if (!check_nb_args(args))
// 		return ;
// 	beforesearch = ft_envlst_search(env, "PWD");
// 	oldpwd = NULL;
// 	if (beforesearch && beforesearch->var_value)
// 		oldpwd = ft_strdup(beforesearch->var_value);
// 	if (!chdir(args[1]))
// 	{
// 		getcwd(pwd, 4096);
// 		pwdsearch = ft_envlst_search(env, "PWD");
// 		if (pwdsearch)
// 			ft_envlst_clearone(&env, pwdsearch);
// 		tmp = ft_strjoin("PWD=", pwd);
// 		ft_envlstadd_back(&env, ft_envlst_new(tmp));
// 		free(tmp);
// 		set_oldpwd(oldpwd, env);
// 	}
// 	else
// 		set_error(args[1], oldpwd);
// }
