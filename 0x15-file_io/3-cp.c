#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error(int error_code, const char *filename1, const char *filename2, int fd);
int copy_file(const char *filename1, const char *filename2);

/**
 * print_error - Prints the appropriate error message for the given error code.
 * @error_code: The error code to print the message for.
 * @filename1: The first filename to print in the error message.
 * @filename2: The second filename to print in the error message.
 * @fd: The file descriptor to print in the error message.
 */
void print_error(int error_code, const char *filename1, const char *filename2, int fd)
{
	switch (error_code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename1);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename2);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			break;
		default:
			break;
	}
}

/**
 * copy_file - Copies the contents of a file to another file.
 * @filename1: The name of the file to copy from.
 * @filename2: The name of the file to copy to.
 *
 * Return: 0 on success, or an appropriate error code.
 */
int copy_file(const char *filename1, const char *filename2)
{
	int fd1, fd2, r, w, c;
	char buffer[BUFFER_SIZE];

	if (!filename1 || !filename2)
		return (-1);

	fd1 = open(filename1, O_RDONLY);
	if (fd1 == -1)
		return (98);

	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd2 == -1)
	{
		c = close(fd1);
		if (c == -1)
			print_error(100, NULL, NULL, fd1);
		return (99);
	}

	do {
		r = read(fd1, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			c = close(fd1);
			if (c == -1)
				print_error(100, NULL, NULL, fd1);
			c = close(fd2);
			if (c == -1)
				print_error(100, NULL, NULL, fd2);
			return (98);
		}

		w = write(fd2, buffer, r);
		if (w == -1)
		{
			c = close(fd1);
			if (c == -1)
				print_error(100, NULL, NULL, fd1);
			c = close(fd2);
			if (c == -1)
				print_error(100, NULL, NULL, fd2);
			return (99);
		}

	} while (r > 0);

	c = close(fd1);
	if (c == -1)
	{
		print_error(100, NULL, NULL, fd1);
		return (100);
	}
	c = close(fd2);
	if (c == -1)
	{
		print_error(100, NULL, NULL, fd2);
		return (100);
	}


