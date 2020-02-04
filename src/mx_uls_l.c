#include "uls.h"

void mx_uls_l(t_list *files) {
	struct stat buff;

	char *str = NULL;

	stat(files->data, &buff);
	str = ctime(&buff.st_mtime);
	
	printf("-rw-r--r-- ");
	printf("%d ", buff.st_nlink); // страные цифры перед выводом
	printf("%d ", buff.st_uid);
	printf("%d ", buff.st_gid);
	printf("%lld ", buff.st_size);

	printf("%s ", str);
	printf("%s\n", files->data);
	//printf("%lld ", buff.st_blocks);
	


	// mx_printint(buff.st_uid);
	// mx_printchar(' ');
	//mx_printint(buff.st_size);
	

}
