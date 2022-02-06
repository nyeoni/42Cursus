/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:35:25 by nkim              #+#    #+#             */
/*   Updated: 2022/02/07 01:58:56 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_cmd(char *cmd, char **envp)
{
	int pipe_fd[2];
	int status;
	pid_t pid;

	if (pipe(pipe_fd) == -1)
		throw_error("pipe error", 1);
	pid = fork();
	if (pid == -1)
		throw_error("process fork fail", 1);
	else if (pid == 0)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			throw_error("redirection error5", 1);
		close(pipe_fd[0]);
		exec_cmd(cmd, envp);
	}
	else
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			throw_error("redirection error4", 1);
		close(pipe_fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	last_process(char *outfile, char *cmd2, char **envp)
{
	int	fd;

	printf("cmd2: %s\n", cmd2);
	fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		perror("file open error");
	if (dup2(fd, STDOUT_FILENO) == -1)
		throw_error("redirection error3", 1);
	exec_cmd(cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int infile;
	int i;

	if (argc < 5)
		throw_error("wrong arguments", 1);
	else
	{
		infile = open(argv[1], O_RDONLY, 0777);
		if (infile == -1)
			throw_error("file open error", 1);
		if (dup2(infile, STDIN_FILENO) == -1)
			throw_error("redirection error1", 1);
		i = -1;
		while (++i < argc - 4)
			pipe_cmd(argv[2 + i], envp);
		// cmd_process(argv, argc - 3, envp);
		last_process(argv[argc - 1], argv[argc - 2], envp);
	}
	return (0);
}
