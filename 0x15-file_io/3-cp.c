#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void print_error(char *msg, char *filename, int code) {
    dprintf(STDERR_FILENO, "%s %s\n", msg, filename);
    exit(code);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    char *file_from = argv[1];
    char *file_to = argv[2];

    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];

    // Open the source file for reading
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        print_error("Error: Can't read from", file_from, 98);
    }

    // Create or truncate the destination file for writing
    fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1) {
        print_error("Error: Can't write to", file_to, 99);
    }

    // Copy the content from source to destination in chunks of 1024 bytes
    while ((bytes_read = read(fd_from, buffer, sizeof(buffer)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1) {
            print_error("Error: Can't write to", file_to, 99);
        }
    }

    if (bytes_read == -1) {
        print_error("Error: Can't read from", file_from, 98);
    }

    // Close the file descriptors
    if (close(fd_from) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return 0;
}
