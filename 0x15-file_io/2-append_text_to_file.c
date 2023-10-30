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
 * append_text_to_file -  appends text at the end of a file
 * @filename : name of file
 * @text_content : NULL terminated string to append to the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	char *buff;
	int fd, wc;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
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
