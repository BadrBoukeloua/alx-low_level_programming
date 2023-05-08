#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *allocate_buffer(int buffer_size);
void close_fd(int fd);

/**
 * allocate_buffer - Allocates memory for a buffer.
 * @buffer_size: The size of the buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(int buffer_size)
{
	char *buffer;

	buffer = malloc(sizeof(char) * buffer_size);

	if (buffer == NULL)
	{
		perror("Error: Unable to allocate memory for buffer\n");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_fd - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
	int status;

	status = close(fd);

	if (status == -1)
	{
		perror("Error: Unable to close file descriptor\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 1.
 * If source file cannot be opened - exit code 2.
 * If destination file cannot be created or written to - exit code 3.
 * If an error occurs while reading from the source or writing to the destination file - exit code 4.
 */
int main(int argc, char *argv[])
{
	int src_fd, dst_fd, read_size, write_size;
	char *buffer;
	const int BUFFER_SIZE = 1024;

	if (argc != 3)
	{
		printf("Usage: %s source_file destination_file\n", argv[0]);
		exit(1);
	}

	buffer = allocate_buffer(BUFFER_SIZE);
	src_fd = open(argv[1], O_RDONLY);

	if (src_fd == -1)
	{
		perror("Error: Unable to open source file\n");
		free(buffer);
		exit(2);
	}

	dst_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (dst_fd == -1)
	{
		perror("Error: Unable to create or write to destination file\n");
		free(buffer);
		close_fd(src_fd);
		exit(3);
	}

	read_size = read(src_fd, buffer, BUFFER_SIZE);

	while (read_size > 0)
	{
		write_size = write(dst_fd, buffer, read_size);

		if (write_size == -1)
		{
			perror("Error: Unable to write to destination file\n");
			free(buffer);
			close_fd(src_fd);
			close_fd(dst_fd);
			exit(4);
		}

		read_size = read(src_fd, buffer, BUFFER_SIZE);
	}

	free(buffer);
	close_fd(src_fd);
	close_fd(dst_fd);

	return (0);
}

