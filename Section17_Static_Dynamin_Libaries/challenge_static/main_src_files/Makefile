
ALL: BUILD_OBJ BUILD_PROG

#build an object file ("-c" - compile or assemble the source files, but do not link)
SRC = main.c
OBJ = main.o
LIB_DIR_PATH = ../lib_dir/
BUILD_OBJ:
	gcc -I $(LIB_DIR_PATH) -c ${SRC} -o ${OBJ}

# link object file with lib archive
LIB_ARCH_PATH = ../lib_dir/lib_string_functions.a
PROG = main
BUILD_PROG:
	gcc ${OBJ} ${LIB_ARCH_PATH} -o ${PROG}