#include "uls.h"

// static char get_flag(t_list *flags) {
//     // t_list *cp_flags = flags;
//     // char flag[] = "l1m";
//     char our_flag = 'C';
//     // char tmp;
// flags = NULL;
//     // for (int i = 0; i < 2 & cp_flags != NULL; i++) {
//     //     for (int j = 0; j < 3; j++) {
//     //     	tmp = (char)cp_flags->data;
//     //         if (tmp	 == flag[j])
//     //             our_flag = flag[j];
//     //     }
//     //     cp_flags = cp_flags->next;
//     // }
//     printf("%c\n", our_flag);
//     return our_flag;
// }

void mx_all_files(t_list *files, t_list *flags) {
    if (files != NULL) {
        switch ('l') {
            case 'l':
                mx_l_flag(files, flags);
                break;
            case 'C':
                mx_big_c_flag(files, flags);
                break;
            case '1':
                mx_one_flag(files, flags);
                break;
            case 'm':
                mx_m_flag(files, flags);
        }
    }
}
