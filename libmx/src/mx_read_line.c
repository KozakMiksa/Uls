#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    int bytes = fd;

    (**lineptr)++;
    buf_size++;
    delim++;
    bytes++;
    return 0;
}
