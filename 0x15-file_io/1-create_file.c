#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * slen - returns length of string
 * @s : given string
 * Return: length of @s
 */
int slen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * create_file -  creates a file
 * @filename : name of file to be created
 * @text_content : NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	char *buff;
	int fd, wc;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return (-1);
	buff = text_content;
	if (buff == NULL)
		wc = write(fd, "", 0);
	else
		wc = write(fd, buff, slen(buff));
	if (wc < 0)
		return (-1);

	close(fd);
	return (1);

}
