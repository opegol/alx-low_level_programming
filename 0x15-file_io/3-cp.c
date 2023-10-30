#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/**
 * close_file - close a file
 * @fd : file descriptor of file to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
		exit(100);
	}
}

/**
 * main - Program that copies the content of a file to another file
 * @ac : number of program arguments
 * @av : array of argument strings
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_ff, fd_ft, rc, wc;
	char *buff;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_ff = open(av[1], O_RDONLY);
	if (fd_ff < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	fd_ft = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 664);

	do {
		buff = malloc(1024 * sizeof(char));
		if (buff == NULL)
			return (-1);
		rc = read(fd_ff, buff, 1024);

		wc = write(fd_ft, buff, rc);
		if (fd_ft == -1 || wc == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
		free(buff);
		if (rc < 1024)
			break;
	} while (rc >= 0);

	close_file(fd_ff);
	close_file(fd_ft);
	return (0);
}
