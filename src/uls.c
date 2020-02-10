#include "uls.h"

void mx_uls(t_list **parser) {
    mx_for_big_r(&parser);
    mx_no_such_file_or_dir(parser[1]);
    mx_all_files(parser[2], parser[0]);
    mx_permission(parser[3]);
    mx_all_directory(parser[4], parser[0]);
}
