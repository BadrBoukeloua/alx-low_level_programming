#include "main.h"


/**
read_textfile- Read text file print to STDOUT.

*/
ssize_t read_textfile(const char *filename, size_t letters)
{
    FILE *file;
    char *buf;
    ssize_t w;
    size_t t;

    if (filename == NULL)
        return (0);

    file = fopen(filename, "r");
    if (file == NULL)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (buf == NULL)
    {
        fclose(file);
        return (0);
    }

    t = fread(buf, sizeof(char), letters, file);
    w = write(STDOUT_FILENO, buf, t);

    free(buf);
    fclose(file);

    return (w);
}
