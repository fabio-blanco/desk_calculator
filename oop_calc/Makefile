APPNAME=dc

CC=g++
CFLAGS= -Wall -g

RM=rm -f

BUILD_DIR = ./build
SRC_DIR = ./src

OBJS=$(addprefix $(BUILD_DIR)/, lexer.o parser.o calculator.o main.o)

all: $(APPNAME)

$(OBJS): | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(APPNAME): $(OBJS)
	$(CC) -o $@ $(OBJS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/calculator.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -o $@  -c $(SRC_DIR)/main.cpp

$(BUILD_DIR)/calculator.o: $(SRC_DIR)/calculator.hpp  $(SRC_DIR)/parser.hpp $(SRC_DIR)/lexer.hpp $(SRC_DIR)/calculator.cpp
	$(CC) $(CFLAGS) -o $@  -c $(SRC_DIR)/calculator.cpp

$(BUILD_DIR)/parser.o: $(SRC_DIR)/parser.hpp $(SRC_DIR)/lexer.hpp $(SRC_DIR)/parser.cpp
	$(CC) $(CFLAGS) -o $@  -c $(SRC_DIR)/parser.cpp

$(BUILD_DIR)/lexer.o: $(SRC_DIR)/lexer.hpp $(SRC_DIR)/lexer.cpp
	$(CC) $(CFLAGS) -o $@  -c $(SRC_DIR)/lexer.cpp

clean: 
	$(RM) $(BUILD_DIR)/*.* $(APPNAME)
