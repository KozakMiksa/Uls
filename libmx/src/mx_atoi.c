#include "libmx.h"

int mx_atoi(char *s) {
    int m = 1;
    int n = 0;
    int i = 0;

    for (; mx_isspace(s[i]) == 1; i++);
    if (s[i] == '-' || s[i] == '+' || mx_isdigit(s[i]) == 1) {
        if (s[i] == '-') {
            m = m * -1;
            i++;
            for (; mx_isdigit(s[i]) == 1; i++)
                n = (10 * n) + s[i] - 48;
        }
        else {
            if (s[i] == '+')
                i++;
            for (; mx_isdigit(s[i]) == 1; i++)
                n = (10 * n) + s[i] - 48;
        }
    }
    return n * m;
}
