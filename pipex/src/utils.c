/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:34:41 by nkim              #+#    #+#             */
/*   Updated: 2022/02/06 15:16:25 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char *cmd, char **envp)
{
	char *PATH;
	char *path;
	char **path_list;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
			break;
		envp++;
	}
	PATH = ft_strchr(*envp, '=')  + 1;
	path_list = ft_split(PATH, ':');
	while (*path_list)
	{
		path = ft_strjoin(*path_list, "/");
		path = ft_strjoin(path, cmd);
		if (!access(path, F_OK))
			return path;
		path_list++;
	}
	return NULL;
}

void	exec_cmd(char *cmd, char **envp)
{
	char *path;
	char **cmds;

	cmds = ft_split(cmd, ' ');
	path = find_path(cmds[0], envp);
	if (path)
		execve(path, cmds, envp);
	else
		throw_error("the location of the command could not be found");
}

void	throw_error(char *message)
{
	if (message)
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n\033[0m", 2);
	}
	else
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n\033[0m", 2);
	}
	exit(EXIT_FAILURE);
}
