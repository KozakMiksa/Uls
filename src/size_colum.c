#include "uls.h"

int mx_size_colum(int buf) {
    int size = 1;

    while (buf / 10 > 0) {
        size++;
        buf /= 10;
    }
    return size;
}
