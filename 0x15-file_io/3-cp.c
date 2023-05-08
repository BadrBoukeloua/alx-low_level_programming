#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void print_error(char *message);
void copy_file(char *source_file, char *destination_file);

/**
 * print_error - Prints an error message to stderr and exits the program.
 * @message: The error message to print.
 */
void print_error(char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(1);
}

/**
 * copy_file - Copies the contents of one file to another.
 * @source_file: The path to the file to copy.
 * @destination_file: The path to the file to copy to.
 *
 * Return: 0 on success, -1 on failure.
 *
 * Description: If the source file cannot be opened for reading, print an error message
 * and return -1. If the destination file cannot be opened for writing, print an error message
 * and return -1. If an error occurs while reading from or writing to the files, print an
 * error message and return -1. Otherwise, return 0.
 */
void copy_file(char *source_file, char *destination_file)
{
	int source_fd, destination_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	source_fd = open(source_file, O_RDONLY);
	if (source_fd == -1)
		print_error("Cannot open source file for reading");

	destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (destination_fd == -1)
	{
		close(source_fd);
		print_error("Cannot open destination file for writing");
	}

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(destination_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(source_fd);
			close(destination_fd);
			print_error("Error occurred while writing to destination file");
		}
	}

	if (bytes_read == -1)
	{
		close(source_fd);
		close(destination_fd);
		print_error("Error occurred while reading from source file");
	}

	close(source_fd);
	close(destination_fd);
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, 1 on failure.
 *
 * Description: If the number of arguments is not 3, print an error message
 * and return 1. Otherwise, call copy_file() with the source and destination
 * file paths and return the result of that function.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
		return 1;
	}

	copy_file(argv[1], argv[2]);

	return 0;
}

