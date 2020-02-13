#include "uls.h"

static void print_names(char *name, int longest) {
    int size_name = mx_strlen(name);

    mx_printstr(name);
    while (size_name < longest) {
        mx_printchar('\t');
        size_name = size_name + 8;
    }
}

void mx_mult_colum(t_list *names, int win_size, int longest, int size_list) {
    int num_colum = win_size / longest;
    int num_str = size_list / num_colum + ((size_list % num_colum) ? 1 : 0);
    t_list *next_data = NULL;

    num_colum = size_list / num_str + ((size_list % num_str) ? 1 : 0);

    for (win_size = 0; win_size < num_str; win_size++) {
        print_names(names->data, longest);
        next_data = names;
        for (int j = 0; j < num_colum - 1; j++) {
            for (int k = 0; k < num_str; k++)
                if (next_data != NULL)
                    next_data = next_data->next;
            if (next_data != NULL)
                print_names(next_data->data, longest);
        }
        mx_printchar('\n');
        names = names->next;
    }
}
