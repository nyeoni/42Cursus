/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:35:25 by nkim              #+#    #+#             */
/*   Updated: 2022/02/06 15:52:54 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_process(char *infile, char *cmd1, int *pipe_fd, char **envp)
{
	int fd;

	fd = open(infile, O_RDONLY, 0777);
	if (fd == -1)
		throw_error("file open error");
	if (dup2(fd, STDIN_FILENO) == -1)
		throw_error("redirection error");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		throw_error("redirection error");
	close(pipe_fd[0]);
	exec_cmd(cmd1, envp);
}

void parent_process(char *outfile, char *cmd2, int *pipe_fd, char **envp)
{
	int fd;

	fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		perror("file open error");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		throw_error("redirection error");
	if (dup2(fd, STDOUT_FILENO) == -1)
		throw_error("redirection error");
	close(pipe_fd[1]);
	exec_cmd(cmd2, envp);
}

int main(int argc, char **argv, char **envp)
{
	int pipe_fd[2];
	int status;
	pid_t pid;
	pid_t wait_pid;

	if (argc != 5)
		throw_error("wrong arguments");
	else
	{
		if (pipe(pipe_fd) == -1)
			throw_error("pipe error");
		pid = fork(); // 순서의 중요성 ^_^ 개빡치네
		if (pid == 0)
			child_process(argv[1], argv[2], pipe_fd, envp);
		else if (pid > 0)
		{
			wait_pid = waitpid(pid, &status, 0);
			parent_process(argv[4], argv[3], pipe_fd, envp);
		}
		else
			throw_error("process fork fail");
	}
}