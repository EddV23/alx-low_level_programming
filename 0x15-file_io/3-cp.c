#include "main.h"

/**
 * copy_file - Copy the content of one file to another
 * @from: Source file descriptor
 * @to: Destination file descriptor
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int copy_file(int from, int to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(to, buffer, bytes_read);
		if (bytes_written == -1)
			exit(99);
	}

	if (bytes_read == -1)
		exit(98);

	exit(0);
}

/**
 * main - Entry point, copy the content of one file to another file
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		close(fd_from);
		exit(99);
	}

	if (copy_file(fd_from, fd_to) != 0)
	{
		close(fd_from);
		close(fd_to);
		exit(99);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from == -1 ? fd_to : fd_from);
		exit(100);
	}

	exit(0);
}
