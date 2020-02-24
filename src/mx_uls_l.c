#include "uls.h"

// char *get_access(stat buff) {
//     char str[] 
// }
// void print_total(t_list *files) {

// }

char *path_to_dir(char *str, char *argv) { // хрень для добавления слеша в конце
    int i = 0;
    char *trs = NULL;

    for (; str[i + 1] != '\0'; i++);
    if (str[i] == '/')
        trs = mx_strjoin(argv, str);
    else
    	trs = mx_strjoin(mx_strcat(argv, "/"), str);
    return trs;
}

void mx_uls_l(t_list *files, char *argv) {
	struct stat buff;
	int size_list = mx_list_size(files);
	

	char *str = NULL;
	int fl = 0;
	int i = 0;

	str = path_to_dir(files->data, argv);
	stat(str, &buff);

	str = ctime(&buff.st_mtime);

	while (mx_isspace(*str) == 0) { // будет функция удаления лишнего из тайм
		str++;
	}
	str++;
	for (; fl < 2; i++) {
		if (str[i] == ':')
			fl++;
	}
	str[i - 1] = '\0';
	while(str[i] != '\0')
		str[i] = '\0';

	
	struct passwd *pw;
	pw = getpwuid(buff.st_uid); // для вывода имени


	//(MX_ISVTX & buff.st_mode) ? mx_printchar('x') : mx_printchar('-');

	printf(" ");
	


	printf("%lld ", buff.st_blocks);
	//printf("-rw-r--r--  ");
	printf("%d ", buff.st_nlink); // страные цифры перед выводом
	printf("%s  ", pw->pw_name);
	printf("%d  ", buff.st_gid);
	printf("%lld ", buff.st_size);
	printf("%s ", str);
	printf("%s\n", files->data);
	

	//system("leaks -q uls");

}




static void dir_or_not(struct stat *buff) {
    if ((buff->st_mode & MX_IFMT) == MX_ISREG)
    	mx_printchar('-');
    else if ((buff->st_mode & MX_IFMT) == MX_ISDIR)
    	mx_printchar('d');
    else if ((buff->st_mode & MX_IFMT) == MX_ISCHR)
    	mx_printchar('c');
    else if ((buff->st_mode & MX_IFMT) == MX_ISBLK)
    	mx_printchar('b');
    else if ((buff->st_mode & MX_IFMT) == MX_ISFIFO)
    	mx_printchar('f');
    else if ((buff->st_mode & MX_IFMT) == MX_ISLNK)
    	mx_printchar('l');
    else if ((buff->st_mode & MX_IFMT) == MX_SOCK)
    	mx_printchar('s');

}

static void socets(struct stat *buff) {
	dir_or_not(buff);
    (MX_IRUSR & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWUSR & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    (MX_IXUSR & buff->st_mode) ? mx_printchar('x') : mx_printchar('-');
    (MX_IRGRP & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWGRP & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    (MX_IXGRP & buff->st_mode) ? mx_printchar('x') : mx_printchar('-');
    (MX_IROTH & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWOTH & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    (MX_IXOTH & buff->st_mode) ? mx_printchar('x') : mx_printchar('-');
}

static char *path_to_dir(char *str, char *argv) { // хрень для добавления слеша в конце
    int i = 0;
    char *trs = NULL;

    for (; str[i + 1] != '\0'; i++);
    if (argv[0] != '.') {
        if (str[i] == '/') {
            trs = mx_strjoin(argv, str);
        }
        else {
    	    trs = mx_strjoin(mx_strcat(argv, "/"), str);
        }
    }
    else {
    	trs = str;
    }
    return trs;
}

void mx_l_flag(t_list *files, t_list *flags, char *dir) {
    struct stat buff;
	t_list *cp_files = files;
	int total = 0;
	char *str = NULL;

	mx_select_sort(&files, flags, mx_get_flag(flags, "ftS", 'C'), dir);
	if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);

/////////////////////////////////////////
    while (cp_files != NULL) {
    	if (dir != NULL)
            str = path_to_dir(cp_files->data, dir);
        else
        	str = cp_files->data;
    	lstat(str, &buff);
    	total += buff.st_blocks;
    	cp_files = cp_files->next;
    }
    mx_printstr("total ");
    mx_printint(total);
    mx_printchar('\n');
/////////////////////////////////////////

    while (files != NULL) {
    	if (dir != NULL)
            str = path_to_dir(files->data, dir);
        else
        	str = files->data;
        lstat(str, &buff);
        socets(&buff);
        mx_printchar(' ');
    mx_printstr(files->data);
    mx_printchar('\n');
        files = files->next;
    }
}