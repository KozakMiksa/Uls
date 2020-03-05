#include "uls.h"

static int count_flows(t_list **parser) {
    int count = -1;

    for (int i = 2; i < 5; i++)
        if (parser[i] != NULL)
            count++;
    return count;
}

void mx_uls(t_list **parser) {
    int flows = count_flows(parser);
    //mx_for_big_r(&parser);
    mx_no_such_file_or_dir(parser[1]);
    mx_all_files(parser[2], parser[0], flows);
    mx_permission(parser[3], flows);
    mx_all_directory(parser[4], parser[0]);
}
