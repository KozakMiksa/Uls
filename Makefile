NAME = uls

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

INC = uls.h

SRC = main.c \
parsing.c \
usage_error.c \
select_flags.c \
check_flags.c \
select_flags_first.c \
select_flags_second.c \
select_flags_third.c \
select_flags_fourth.c \
select_flags_fifth.c \
principal_printable_flag.c \
size_sort.c \
time_sort.c \
\
uls.c \
for_big_r.c \
no_such_file_or_dir.c \
all_files.c \
permission.c \
all_directory.c \
ascii_sort.c \
m_flag.c \
big_c_flag.c \
l_flag.c \
one_flag.c \
select_sort.c \
get_flag.c \
mult_colum.c \
r_sort.c \
path_to_dir.c \

OBJ = main.o \
parsing.o \
usage_error.o \
select_flags.o \
check_flags.o \
select_flags_first.o \
select_flags_second.o \
select_flags_third.o \
select_flags_fourth.o \
select_flags_fifth.o \
principal_printable_flag.o \
size_sort.o \
time_sort.o \
\
uls.o \
for_big_r.o\
no_such_file_or_dir.o \
all_files.o \
permission.o \
all_directory.o \
ascii_sort.o \
m_flag.o \
big_c_flag.o \
l_flag.o \
one_flag.o \
select_sort.o \
get_flag.o \
mult_colum.o \
r_sort.o \
path_to_dir.o \


all: install clean

install:
	@make install -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean: 
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
