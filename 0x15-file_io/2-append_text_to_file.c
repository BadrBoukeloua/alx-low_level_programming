#include "main.h"

/**
 * append_content_to_file - Appends the content of a string to the end of a file.
 *
 * @filename: The name of the file to append to.
 * @content: The content to append to the file.
 *
 * Return: 1 if the function is successful, or -1 if an error occurs.
 */
int append_content_to_file(const char *filename, char *content)
{
    int file_descriptor, bytes_written, content_length = 0;

    if (filename == NULL)
        return (-1);

    if (content != NULL)
    {
        while (content[content_length])
            content_length++;
    }

    file_descriptor = open(filename, O_WRONLY | O_APPEND);
    if (file_descriptor == -1)
        return (-1);

    bytes_written = write(file_descriptor, content, content_length);
    if (bytes_written == -1)
        return (-1);

    close(file_descriptor);
    return (1);
}

