#include "main.h"
#include <stdblib.h>
#include <stdio.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 * by romi .
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
        return 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    char *buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return 0;

    ssize_t n_read = fread(buffer, sizeof(char), letters, fp);
    if (n_read == 0)
    {
        free(buffer);
        fclose(fp);
        return 0;
    }

    printf("%s", buffer);

    free(buffer);
    fclose(fp);

    return n_read;
}
