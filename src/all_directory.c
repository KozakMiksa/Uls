#include "uls.h"

static void default_flag(char *name, t_list **names_dir) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(name);
    while ( (entry = readdir(dir)) != NULL)
        if (entry->d_name[0] != '.') 
            mx_push_back(names_dir, entry->d_name);
    closedir(dir);
}

static void a_flag(char *name, t_list **names_dir) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL)
        mx_push_back(names_dir, entry->d_name);
    closedir(dir);
}

static void big_a_flag(char *name, t_list **names_dir) {
    DIR *dir;
    struct dirent *entry;
    int stop_flag = 0;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL) {
        if (stop_flag > 1)
            mx_push_back(names_dir, entry->d_name);
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

void mx_all_directory(t_list *dir, t_list *flags) {
    char flag = mx_get_flag(flags, "aA", 'C');
    t_list *names = NULL;

    while (dir != NULL) {
    	// mx_printstr(dir->data);
    	// mx_printchar(':');
     //    mx_printchar('\n');
        names = names_in_list(dir->data, flag);
        mx_all_files(names, flags);
        dir = dir->next;
        // mx_printchar('\n');
    }
}
