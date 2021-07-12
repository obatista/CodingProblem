#build file
CC = g++

CFLAGS = -Wall -g

DIR := ${CURDIR}
BUILD_DIR := $(DIR)/../build

INC_DIR = $(DIR)/../include
INCLUDES = -I$(INC_DIR)


SRC_DIR = $(DIR)/../src
SRCS = $(SRC_DIR)/codingproblem.cpp $(SRC_DIR)/Point.cpp $(SRC_DIR)/Track.cpp $(SRC_DIR)/Util.cpp 


OBJS = $(SRCS:.cpp=.o)

# executable file 
MAIN = codingproblem

.PHONY: depend clean

all:    $(MAIN) configure
	@echo  Compiling codingproblem

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

configure:
	mv $(OBJS) $(BUILD_DIR)
	mv $(MAIN) ..
	
clean:
	$(RM) $(BUILD_DIR)/*.o
	$(RM) ../$(MAIN)