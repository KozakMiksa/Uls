#include "uls.h"

void mx_uls(t_list **parser) {
    int check = 0;

    for (int i = 1; i < 5; i++)
        mx_ascii_sort(&parser[i]);
    //mx_for_big_r(&parser);
    mx_no_such_file_or_dir(parser[1]);
    if (parser[3] != NULL || parser[4] != NULL)
        check = 1;
    mx_all_files(parser[2], parser[0], check);
    check = 0;
    if (parser[4] != NULL)
        check = 1;
    mx_permission(parser[3], check);
    check = 0;
    if (parser[1] != NULL || parser[2] != NULL || parser[3] != NULL)
        check = 1;
    mx_all_directory(parser[4], parser[0], check);
}
