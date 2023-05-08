#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads and prints the contents of a text file.
 * @filename: Name of the file to read.
 * @num_letters: Number of letters to read from the file.
 *
 * Return: Number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t num_letters)
{
	char *buffer;
	ssize_t file_descriptor, num_bytes_read, num_bytes_written;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * num_letters);
	if (buffer == NULL)
		return (0);

	num_bytes_read = read(file_descriptor, buffer, num_letters);
	num_bytes_written = write(STDOUT_FILENO, buffer, num_bytes_read);

	free(buffer);
	close(file_descriptor);

	return (num_bytes_written);
}

