CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = wrapper
SRC = wrapper.cpp
OBJ = wrapper.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

wrapper.o: wrapper.cpp
	$(CXX) $(CXXFLAGS) -Isrc -c wrapper.cpp -o wrapper.o

clean:
	rm -f driver/*.o
	rm -f src/*.o
	rm -f $(TARGET)

.PHONY: all clean