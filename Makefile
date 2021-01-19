CC = gcc

INCLUDE_PATH = -I./include
SRC_PATH = ./src
BUILD_PATH = ./build
EXECUTABLE = main
OBJECTS = $(addprefix $(BUILD_PATH)/, color.o cursor.o screen.o user.o util.o main.o)

CFLAGS = -Wall $(INCLUDE_PATH)

.PHONY: all
all : main

main : build $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS) 

$(BUILD_PATH)/%.o : $(SRC_PATH)/%.c 
	$(CC) -c $(CFLAGS) -o $@ $<

build :
	mkdir -p $(BUILD_PATH)

.PHONY: clean
clean :
	rm -rd $(BUILD_PATH)
	rm $(EXECUTABLE)