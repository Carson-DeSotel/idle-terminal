CC  = gcc 		# compiler

LIB = ./lib
SRCS = ./main.c ./lib/screen.c ./lib/color.c ./lib/cursor.c ./lib/util.c
OBJS = main.o ./lib/screen.o ./lib/color.o ./lib/cursor.o ./lib/util.o

deps :
	make -C ${LIB} all
	${CC} -c main.c

all : ${OBJS}
	make deps
	${CC} -o main ${OBJS}

clean :
	make -C ${LIB} clean 
	rm *.o
	rm main