#include "uls.h"

static t_list *namesInList(char *argv);

int longestName(t_list *list) { // определяю самое длинное слово + размер столбца
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

void printNames(char *name, int longest) {
    int sizeName = mx_strlen(name);

    mx_printstr(name);
    while (sizeName < longest) {
        mx_printchar('\t');
        sizeName = sizeName + 8;
    }
}

void printMultiColum(t_list *namesDir, int winSize, int longest, int sizeList) {
    int countColums = winSize / longest;
    int countStr = sizeList / countColums + ((sizeList % countColums) ? 1 : 0);
    t_list *nextData = NULL;

    countColums = sizeList / countStr + ((sizeList % countStr) ? 1 : 0);

    for (int i = 0; i < countStr; i++) {
        printNames(namesDir->data, longest);
        nextData = namesDir;
        for (int j = 0; j < countColums - 1; j++) {
            for (int k = 0; k < countStr; k++) {
                if (nextData != NULL) {
                    nextData = nextData->next;
                }
            }
            if (nextData != NULL) {
                printNames(nextData->data, longest);
            }
            
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



int main(int argc, char *argv[]) {
    t_list *filesDir = NULL;

    if (argc == 2) {
        filesDir = namesInList(argv[1]);

        uls(filesDir);
    }
    else {
        filesDir = namesInList(argv[2]);
        while (filesDir != NULL) {
            mx_uls_l(mx_asciiSort(filesDir), argv[2]);
            filesDir = filesDir->next;
        }
    }
    // system(  "leaks -q uls");
    return 0;
}

static t_list *namesInList(char *argv) {
    DIR *dir;
    struct dirent *entry;
    t_list *namesDir = NULL;
    int fd = open(argv, O_RDONLY);
    

    dir = opendir(argv);
    if (!dir) {
        if (fd > 0) {
            namesDir = mx_create_node(argv);
        }
        else {
            perror(mx_strjoin("uls: ", argv));
            exit(1);
        }
    }
    else {
        while ( (entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.') {
                if (namesDir == NULL)
                    namesDir = mx_create_node(entry->d_name);
                else
                    mx_push_front(&namesDir, entry->d_name);
            }
        }
    }
    //closedir(dir);
    return	namesDir;
}
