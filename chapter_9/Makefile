APPNAME=dc

CC=g++
CFLAGS= -Wall -g

RM=rm -f

BUILD_DIR = ./build
SRC_DIR = ./src

OBJS=$(BUILD_DIR)/table.o $(BUILD_DIR)/driver.o $(BUILD_DIR)/lexer.o $(BUILD_DIR)/parser.o $(BUILD_DIR)/main.o

all: $(APPNAME)

$(APPNAME): $(OBJS)
	$(CC) -o $@ $(OBJS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/parser.hpp $(SRC_DIR)/lexer.hpp $(SRC_DIR)/error.hpp $(SRC_DIR)/table.hpp $(SRC_DIR)/driver.hpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC_DIR)/main.cpp

$(BUILD_DIR)/parser.o: $(SRC_DIR)/parser_impl.hpp $(SRC_DIR)/parser.hpp $(SRC_DIR)/error.hpp $(SRC_DIR)/lexer.hpp $(SRC_DIR)/parser.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC_DIR)/parser.cpp

$(BUILD_DIR)/lexer.o: $(SRC_DIR)/lexer.hpp $(SRC_DIR)/error.hpp $(SRC_DIR)/driver.hpp $(SRC_DIR)/lexer.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC_DIR)/lexer.cpp

$(BUILD_DIR)/driver.o: $(SRC_DIR)/driver.hpp $(SRC_DIR)/driver.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC_DIR)/driver.cpp

$(BUILD_DIR)/table.o: $(SRC_DIR)/table.hpp $(SRC_DIR)/table.cpp
	$(CC) $(CFLAGS) -o $@  -c $(SRC_DIR)/table.cpp

clean: 
	$(RM) $(BUILD_DIR)/*.*
