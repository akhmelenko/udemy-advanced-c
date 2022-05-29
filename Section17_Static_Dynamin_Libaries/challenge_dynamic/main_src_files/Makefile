
ALL: BUILD_OBJ BUILD_PROG

#build an object file ("-c" - compile or assemble the source files, but do not link)
SRC = main.c
OBJ = main.o
LIB_DIR_PATH = ../lib_dir/
BUILD_OBJ:
	gcc -I $(LIB_DIR_PATH) -c ${SRC} -o ${OBJ}

# link object file with lib archive
PROG = main
DLIBNAME = mystring
BUILD_PROG:
	gcc -o ${PROG} ${OBJ} -L${LIB_DIR_PATH} -l ${DLIBNAME}