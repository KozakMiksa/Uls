#include "uls.h"

static t_list *namesInList(char *argv);

int longestName(t_list *list) {
    int lenght = 0;
    int tmp = 0;

    while (list != NULL) {
        tmp = mx_strlen(list->data);
        if (tmp > lenght)
            lenght = tmp;
        list = list->next;
    }
    if (lenght % 8 == 0)
        lenght++;
    while (lenght % 8 != 0)
        lenght++;
    return lenght;
}

void printMultiColum(t_list *namesDir, int winSize, int lenght, int sizeList) {
    int countColums = winSize / lenght;
    int countStr = sizeList / countColums + ((sizeList % countColums) ? 1 : 0);
    t_list *nextData = NULL;

    printf("%s %d\n %s %d\n", "1 countColums", countColums, "countStr", countStr);

    countColums = sizeList / countStr + ((sizeList % countStr) ? 1 : 0);
    printf("%s %d\n\n", "2 countColums", countColums);

    for (int i = 0; i < countStr; i++) {
        mx_printstr(namesDir->data);
        mx_printchar('\t');
        nextData = namesDir;
        for (int j = 0; j < countColums - 1; j++) {
            for (int k = 0; k < countStr; k++) {
                if (nextData->next == NULL) {
                    
                }
                else {
                    nextData = nextData->next;
                }
            }
            mx_printchar(j + 48);
            mx_printstr(nextData->data);
            mx_printchar('\t');
            
        }
        mx_printchar('\n');
        namesDir = namesDir->next;
    } 
}

void uls(t_list *namesDir) {
	int lenght = 0;
    int sizeList = 0;
    struct winsize ws;

    sizeList = mx_list_size(namesDir);
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    lenght = longestName(namesDir);
    namesDir = mx_asciiSort(namesDir);


    
    printMultiColum(namesDir, ws.ws_col, lenght, sizeList);
}



void mx_errors(int argc, char *argv[]) {
	argc++;
	if (!argv) {
		write(1, "1", 1);
	}
}

int main(int argc, char *argv[]) {
    t_list *filesDir = NULL;

    mx_errors(argc, argv);
    filesDir = namesInList(argv[1]);
    uls(filesDir);

    //system("leaks -q uls");
    return 0;
}

static t_list *namesInList(char *argv) {
    DIR *dir;
    struct dirent *entry;
    t_list *namesDir = NULL;

    dir = opendir(argv);
    if (!dir) {
        perror("diropen");
        exit(1);
    }
    while ( (entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            if (namesDir == NULL)
                namesDir = mx_create_node(entry->d_name);
            else
                mx_push_front(&namesDir, entry->d_name);
        }
    }
    closedir(dir);
    return	namesDir;
}
