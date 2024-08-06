#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char mystr[] = "Hello World";
    int fd;

    // Create and open a file for writing
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write the string to the file
    if (write(fd, mystr, sizeof(mystr) - 1) < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    // Close the file
    if (close(fd) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}

