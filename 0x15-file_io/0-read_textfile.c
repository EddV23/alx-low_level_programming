#include "main.h"

/**
 * read_textfile - reads a text file and prints it to
 *                 the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print,
 *         0 if the file cannot be opened or read, filename is NULL,
 *         or write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_check, write_check;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	read_check = read(fd, buf, letters);
	if (read_check == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	write_check = write(STDOUT_FILENO, buf, read_check);
	if (write_check == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	close(fd);
	free(buf);
	return (read_check);
}
