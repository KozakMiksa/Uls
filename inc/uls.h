#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <dirent.h>
#include <time.h>
#include <pwd.h>

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

t_list *mx_asciiSort(t_list *l);
void mx_uls_l(t_list *files, char *argv);

#endif
