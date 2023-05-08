#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: A pointer to the name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         Otherwise - the number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount, wcount;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	rcount = read(fd, buffer, letters);
	if (rcount == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	wcount = write(STDOUT_FILENO, buffer, rcount);
	if (wcount == -1 || wcount != rcount)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);

	return (wcount);
}

