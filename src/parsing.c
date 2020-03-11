#include "uls.h"

static void add_to_parser(char *argv, t_list **parser, int k);
// static void print_parser(t_list **parser);
static void distributor(char *argv, t_list **parser);

t_list **mx_parsing(int i, int argc, char **argv, t_flags *true_flags) {
    t_list **parser = malloc(5 * sizeof(t_list *));

    for (int h = 0; h < 5; h++)
        parser[h] = NULL;
    parser[0] = mx_create_node("C");
    mx_check_flags_first(parser, true_flags);
    mx_check_flags_second(parser, true_flags);
    if (i == 0)
        parser[4] = mx_create_node(".");
    else 
        for (; i < argc; i++)
            distributor(argv[i], parser);
    // print_parser(parser);
    return parser;
}

static void add_to_parser(char *argv, t_list **parser, int k) {
    char *str = mx_strdup(argv);

    mx_push_back(&parser[k], str);
}

static void distributor(char *argv, t_list **parser) {
    DIR *dir = NULL;
    int fd = 0;

    fd = open(argv, O_RDONLY);
    dir = opendir(argv);
    if (!dir) {
        if (errno == EBADF) {
            write(2, "uls: ", 5);
            write(2, argv, mx_strlen(argv));
            write(2, ": Bad file descriptor\n", 22);
        }
        if (errno == ENOENT)
            add_to_parser(argv, parser, 1);
        if (fd > 0)
            add_to_parser(argv, parser, 2);
        if (errno == EACCES)
            add_to_parser(argv, parser, 3);
    }
    else
        add_to_parser(argv, parser, 4);
    close(fd);
    closedir(dir);
}

// static void print_parser(t_list **parser) {
//     for (int i = 0; i < 5; i++) {
//         mx_printstr("Potok ");
//         mx_printint(i);
//         mx_printchar('\n');
//         while (parser[i] != NULL) {
//             mx_printstr(parser[i]->data);
//             mx_printchar(' ');
//             parser[i] = parser[i]->next;
//         }
//         mx_printchar('\n');
//     }
// }
