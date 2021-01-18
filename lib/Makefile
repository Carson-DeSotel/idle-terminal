CC = gcc

%.o : %.c
	${CC} -c -o $@ $<

all : color.o cursor.o screen.o util.o

clean :
	rm *.o