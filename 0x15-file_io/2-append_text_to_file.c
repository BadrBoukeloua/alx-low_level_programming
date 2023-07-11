#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**

append_text_to_file - Appends text at the end of a file.
@filename: A pointer to the name of the file.
@text_content: The string to add to the end of the file.
Return: If the function fails or filename is NULL - -1.
arduino
Copy code
    If the file does not exist or the user lacks write permissions - -1.
markdown
Copy code
    Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
    if (filename == NULL)
        return -1;

    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return -1;

    if (text_content != NULL)
    {
        ssize_t len = 0;
        while (text_content[len] != '\0')
            len++;

        ssize_t bytes_written = write(fd, text_content, len);
        if (bytes_written == -1)
        {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}
