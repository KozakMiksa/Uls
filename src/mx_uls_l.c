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
