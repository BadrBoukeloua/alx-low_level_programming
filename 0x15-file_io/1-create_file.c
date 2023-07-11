#include "main.h"

/**
create_file - Creates a file.

*/
int create_file(const char *filename, char *text_content)
{
    FILE *file;
    int result = -1;

     if (filename == NULL) return -1;

    file = fopen(filename, "w");
    if (file == NULL)
        return -1;

    if (text_content != NULL)
    {
        result = fprintf(file, "%s", text_content);
        if (result < 0)
        {
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return 1;
}

