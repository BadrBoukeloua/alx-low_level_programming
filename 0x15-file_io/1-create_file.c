#include "main.h"


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
    FILE *file;
    int result = -1;
    size_t len = 0;

    if (filename == NULL)
        return -1;

    file = fopen(filename, "w");
    if (file == NULL)
        return -1;

    if (text_content != NULL)
    {
        while (text_content[len] != '\0')
            len++;
    }

    result = fwrite(text_content, sizeof(char), len, file);
    if (result < len)
    {
        fclose(file);
        return -1;
    }

    fclose(file);
    return 1;
}
