#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile -  reads a text file and prints it
 *		to the POSIX standard output.
 * @filename : file to be read
 * @letters : the number of letters to be read and printed
 * Return: actual number of letters it could read and print
 *	OR 0, if file could not be opened; if filename is NULL
 *	or if write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	int fd, rc, wc;

	if (filename == NULL)
	return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	buff = malloc(letters * sizeof(char));
	rc = read(fd, buff, letters);
	if (rc < 0)
		return (0);
	wc = write(STDOUT_FILENO, buff, rc);
	if (wc < 0 || wc < rc)
		return (0);
	free(buff);
	close(fd);
	return (wc);

}
