CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = build/pong

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(BIN)
