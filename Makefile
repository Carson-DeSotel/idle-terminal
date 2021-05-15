CC = gcc

INCLUDE_PATH = -I./include
SRC_PATH = ./src
BUILD_PATH = ./build
EXECUTABLE = idle-term
OBJECTS = $(addprefix $(BUILD_PATH)/, idle-term.o bar.o graphics.o menu.o)
DATA = user.dat

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
	rm $(DATA)