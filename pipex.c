/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:51 by yhamdan           #+#    #+#             */
/*   Updated: 2024/11/15 00:32:23 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perr(int i, char **argv, int pipefd[2])
{
	if (i == -1)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		ft_putstr_fd(argv[4], 2);
		write(2, "\n", 1);
	}
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		wait(0);
	}
}

void	cmd2(int pipefd[2], char *argv[], int *argc, char **envp)
{
	char	*cmd[4];

	cmd[0] = "/bin/sh";
	cmd[1] = "-c";
	cmd[2] = argv[argc[0] - 2];
	cmd[3] = NULL;
	close((pipefd[1]));
	dup2(argc[1], STDOUT_FILENO);
	close(argc[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	if (execve("/bin/sh", cmd, envp) == -1)
		perror("command failed\n");
}

int	child(int pipefd[2], char *argv[], char **envp)
{
	char	*cmd[4];
	int		fd;

	cmd[0] = "/bin/sh";
	cmd[1] = "-c";
	cmd[2] = argv[2];
	cmd[3] = NULL;
	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	if (fd != -1)
	{
		execve("/bin/sh", cmd, envp);
		perror("execve failed\n");
		exit(1);
	}
	return (-9999);
}

void	parent(char **argv, int *pipefd, int argc, char **envp)
{
	int	id;
	int	fd;

	id = fork();
	if (!id)
		id = child(pipefd, argv, envp);
	else
	{
		waitpid(id, NULL, 0);
		fd = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd == -1)
			id = -9999;
		if (access(argv[argc - 1], W_OK))
			perr(access(argv[argc - 1], W_OK), argv, pipefd);
		else
			id = fork();
		if (!id)
			cmd2(pipefd, argv, (int []){argc, fd}, envp);
		else
			perr(0, argv, pipefd);
	}
	if ((id || access(argv[argc - 1], W_OK)) && id != -9999)
		close(fd);
}

int	main(int argc, char *argv[], char **envp)
{
	int	pipefd[2];

	if (argc != 5)
		return (write(2, "not enough inputs\n", 19), 1);
	if (pipe(pipefd) == -1)
		exit(1);
	if (access(argv[1], R_OK) == -1 || argv[2][0] == 0 || argv[3][0] == 0)
	{
		ft_putstr_fd("zsh: permission denied: ", 2);
		if (!(argv[2][0] == 0 || argv[3][0] == 0))
			ft_putstr_fd(argv[1], 2);
		write(2, "\n", 1);
	}
	parent(argv, pipefd, argc, envp);
	return (0);
}
