#include "libmx.h"

static int count_read_bytes(const char *file) {
    int count = 0;
    char buf[1];
    int read_bytes = 0;
    int fd = open(file, O_RDONLY);

    if (fd < 0) 
        return 0;
    read_bytes = read(fd, buf, sizeof(buf));
    if (read_bytes <= 0) 
        return 0;
    while (read_bytes > 0) {
        count++;
        read_bytes = read(fd, buf, sizeof(buf));
    }
    close(fd);
    return count;
}

char *mx_file_to_str(const char *file) {
    char *s = NULL;
    char *str = NULL;
    int bytes = 0;
    char buf[1];
    int fd = 0;

    if (!file) 
        return NULL;
    fd = open(file, O_RDONLY);
    s = mx_strnew(count_read_bytes(file));
    str = s;
    bytes = read(fd, buf, sizeof(buf));
    for (; bytes > 0; s++) {
        *s = *buf;
        bytes = read(fd, buf, sizeof(buf));
    }    
    close(fd);
    return str;
}
