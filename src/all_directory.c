#include "uls.h"

static void default_flag(char *name, t_list **names_dir) {
    DIR *dir;
    struct dirent *entry;
    char *str = NULL;

    dir = opendir(name);
    while ( (entry = readdir(dir)) != NULL)
        if (entry->d_name[0] != '.') {
        	str = mx_strdup(entry->d_name);
            mx_push_back(names_dir, str);
        }
    closedir(dir);
}

static void a_flag(char *name, t_list **names_dir) {
    DIR *dir;
    struct dirent *entry;
    char *str = NULL;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL) {
        str = mx_strdup(entry->d_name);
        mx_push_back(names_dir, str);
    }
    closedir(dir);
}

static void big_a_flag(char *name, t_list **names_dir) {
    DIR *dir;
    struct dirent *entry;
    int stop_flag = 0;
    char *str = NULL;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL) {
        if (stop_flag > 1) {
            str = mx_strdup(entry->d_name);
            mx_push_back(names_dir, str);
        }
        stop_flag++;
    }
    closedir(dir);
}

static t_list *names_in_list(char *name, char flag) {
    t_list *names_dir = NULL;
    
    switch (flag) {
        case 'a':
            a_flag(name, &names_dir);
            break;
        case 'A':
            big_a_flag(name, &names_dir);
            break;
        default:
            default_flag(name, &names_dir);
    }
    return names_dir;
}

static void free_list(t_list *names) { // сделать глобальной, проверить где можно юзать еще
    t_list *cp = names;

    while (names != NULL) {
        free(names->data);
        names = names->next;
    }
    while (cp != NULL) {
        mx_pop_front(&cp);
    }
}

void mx_all_directory(t_list *dir, t_list *flags, int flows) {
    char flag = mx_get_flag(flags, "aA", 'C');
    t_list *names = NULL;
    int i = mx_list_size(dir);

    while (dir != NULL) {
        names = names_in_list(dir->data, flag);
        if (i > 1 || flows > 0) {
            mx_printstr(dir->data);
            mx_printstr(":\n");
        }
        mx_print_for_dir(names, flags, dir->data);
        if (dir->next != NULL)
            mx_printchar('\n');
        free_list(names);
        // free(dir->data);
        dir = dir->next;
    }
}
