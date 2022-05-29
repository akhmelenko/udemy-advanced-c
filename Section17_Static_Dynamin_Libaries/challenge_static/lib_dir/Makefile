
ALL: BUILD_OBJ BUILD_ARCH

# create object file
SRC = string_functions.c
OBJ = lib_string_functions.o
BUILD_OBJ:
	gcc -c ${SRC} -o ${OBJ}

# create archive file
ARCH = lib_string_functions.a
BUILD_ARCH:
	ar rcs ${ARCH} ${OBJ}