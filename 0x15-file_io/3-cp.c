#include "main.h"

/**
 * copy_file - Copy the content of one file to another
 * @from: Source file descriptor
 * @to: Destination file descriptor
 * @av: Argument vector
 *
 * Return: void
 */
void copy_file(int from, int to, char **av)
{
	if (from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	if (to == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[2]);
		exit(99);
	}
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
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	copy_file(fd_from, fd_to, av);

	bytes_read = sizeof(buffer);
	while (bytes_read)
	{
		bytes_read = read(fd_from, buffer, sizeof(buffer));
		if (bytes_read == -1)
			copy_file(-1, 0, av);
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			copy_file(0, -1, av);
	}
	if (close(fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	/*
	 *if (close(fd_from) == -1 || close(fd_to) == -1){
	 *	dprintf(2, "Error: Can't close fd %d\n", fd_from == -1 ? fd_to : fd_from);
	 *	exit(100);}
	 */
	return (0);
}
