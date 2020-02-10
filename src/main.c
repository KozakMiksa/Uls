#include "uls.h"

int main(int argc, char *argv[]) {
    t_list **parser = NULL;
    char *usage_flags = mx_strnew(20);

    usage_flags = "ACFGRSTacefhlmprtu1@";
    parser = mx_usage_error(argc, argv, usage_flags);
    mx_uls(parser);

    return 0;
}
