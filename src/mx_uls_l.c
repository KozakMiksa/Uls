#include "uls.h"

void mx_uls_l(t_list *files) {
	struct stat buff;

	stat(files->data, &buff);
	mx_printint(buff.st_uid);
	mx_printchar(' ');
	mx_printint(buff.st_size);
	printf("%s\n", files->data);
}
