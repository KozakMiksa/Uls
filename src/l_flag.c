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
    	mx_printchar('p');
    else if ((buff->st_mode & MX_IFMT) == MX_ISLNK)
    	mx_printchar('l');
    else if ((buff->st_mode & MX_IFMT) == MX_ISSOCK)
    	mx_printchar('s');
}

static void socets(struct stat *buff) {
    dir_or_not(buff);
    (MX_IRUSR & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWUSR & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    if (MX_ISUID & buff->st_mode) 
        (MX_IXUSR & buff->st_mode) ? mx_printchar('s') : mx_printchar('S');
    else     
        (MX_IXUSR & buff->st_mode) ? mx_printchar('x') : mx_printchar('-');
    (MX_IRGRP & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWGRP & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    if (MX_ISGID & buff->st_mode) 
        (MX_IXGRP & buff->st_mode) ? mx_printchar('s') : mx_printchar('S');
    else     
        (MX_IXGRP & buff->st_mode) ? mx_printchar('x') : mx_printchar('-');
    (MX_IROTH & buff->st_mode) ? mx_printchar('r') : mx_printchar('-');
    (MX_IWOTH & buff->st_mode) ? mx_printchar('w') : mx_printchar('-');
    if (MX_ISVTX & buff->st_mode) 
        (MX_IXOTH & buff->st_mode) ? mx_printchar('t') : mx_printchar('T');  
    else     
        (MX_IXOTH & buff->st_mode) ? mx_printchar('x') : mx_printchar('-');
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


void mx_l_flag(t_list *files, t_list *flags, char *dir) {
    struct stat buff;
	char *str = NULL;

	mx_select_sort(&files, flags, mx_get_flag(flags, "ftS", 'C'), dir);
	if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);

    while (files != NULL) {
        if (dir != NULL)
            str = mx_path_to_dir(files->data, dir);
        else
        	str = files->data;
        lstat(str, &buff);
        socets(&buff);
        attributes_and_acl(str);
        mx_printchar(' ');
        mx_printstr(files->data);
        mx_printchar('\n');
        files = files->next;
    }
}
