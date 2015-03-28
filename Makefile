#
# ICP 2014/2015 Makefie
#
CXX = $(shell command -v g++-4.8 >/dev/null 2>&1 && echo -n "g++-4.8" || echo -n "g++")

SRC_FOLDER = src
OBJ_FOLDER = build

CFLAGS = -Wall -Wextra -c --std=c++11


LIB_SRCS = $(wildcard $(SRC_FOLDER)/lib/*.cpp)
LIB_OBJS = $(addprefix $(OBJ_FOLDER)/lib/, $(notdir $(patsubst %.cpp, %.o, $(LIB_SRCS))))

all: lib

lib: $(LIB_OBJS)


$(OBJ_FOLDER)/lib/%.o: $(SRC_FOLDER)/lib/%.cpp
	@mkdir -p $(OBJ_FOLDER)/lib
	$(CXX) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	rm -rf build/*
