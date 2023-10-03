#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *alloc_buffer(char *fp);
void _close(int fd);

/**
 * alloc_buffer - allocates memory for buffer
 * @fp:file to copy to
 * Return: pointer to buffer
 */
char *alloc_buffer(char *fp)
{
	char *buf;

	buf = malloc(1024 * sizeof(char));

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", fp);
		exit(99);
	}

	return (buf);
}

/**
 * _close - close file descriptors
 * @fd: file descriptor to close
 */
void _close(int fd)
{
	int cls;

	cls = close(fd);

	if (cls < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of program arguments
 * @argv: array of strings
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, rd, wr;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = alloc_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	rd = read(file_from, buf, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 00664);

	while (rd > 0)
       	{
		if (file_from < 0)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		wr = write(file_to, buf, rd);
		if (file_to < 0 || wr < 0)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		rd = read(file_from, buf, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	}

	free(buf);
	_close(file_from);
	_close(file_to);

	return (0);
}

