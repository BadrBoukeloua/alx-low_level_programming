#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**

create_file - Creates a file.
@filename: A pointer to the name of the file to create.
@text_content: A pointer to a string to write to the file.
Return: If the function fails - -1.
markdown
Copy code
    Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
    if (filename == NULL)
        return -1;

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
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
