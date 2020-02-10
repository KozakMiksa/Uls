#include "libmx.h"

int mx_get_index(char *str, char flag) {
    int index = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == flag)
            index = i;
    }
    return index;
}
