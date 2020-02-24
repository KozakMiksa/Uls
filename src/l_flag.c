#include "uls.h"

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
    if (MX_ISUID & buff->st_mode) 
        if (MX_IXUSR & buff->st_mode)
            mx_printchar('s');
        else
            mx_printchar('S');  
    else     
        if (MX_IXUSR & buff->st_mode)
            mx_printchar('x');
        else
            mx_printchar('-');  
    (MX_IRGRP & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWGRP & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    if (MX_ISGID & buff->st_mode) 
        if (MX_IXGRP & buff->st_mode)
            mx_printchar('s');
        else
            mx_printchar('S');  
    else     
        if (MX_IXGRP & buff->st_mode)
            mx_printchar('x');
        else
            mx_printchar('-'); 
    (MX_IROTH & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWOTH & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    if (MX_ISVTX & buff->st_mode) 
        if (MX_IXOTH & buff->st_mode)
            mx_printchar('t');
        else
            mx_printchar('T');  
    else     
        if (MX_IXOTH & buff->st_mode)
            mx_printchar('x');
        else
            mx_printchar('-'); 
}

static void attributes_and_acl(char *files) {
    int xattr = listxattr(files, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(files, ACL_TYPE_EXTENDED);

    if (xattr > 0)
        mx_printchar('@');
    else if (acl != NULL) 
        mx_printchar('+');
    else
        mx_printchar(' ');
    acl_free(acl);
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
        attributes_and_acl(str);
        mx_printchar(' ');
    mx_printstr(files->data);
    mx_printchar(' ');   
    printf("%s", ctime(&buff.st_mtime));
    //mx_printchar('\n');
        files = files->next;
    }
}
