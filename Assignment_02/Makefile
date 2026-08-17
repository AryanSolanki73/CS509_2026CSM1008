CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = program

SRC = driver/main.cpp \
      src/bellmanFord.cpp \
      src/floydWarshall.cpp \
      src/CSR.cpp

OBJ = driver/main.o \
      src/bellmanFord.o \
      src/floydWarshall.o \
      src/CSR.o


all: $(TARGET)


# --------------------------------------------------
# Link
# --------------------------------------------------

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)


# --------------------------------------------------
# main.cpp
# --------------------------------------------------

driver/main.o: driver/main.cpp
	$(CXX) $(CXXFLAGS) -Isrc \
	-c driver/main.cpp -o driver/main.o


# --------------------------------------------------
# Bellman-Ford
# --------------------------------------------------

src/bellmanFord.o: src/bellmanFord.cpp src/bellmanFord.h src/CSR.h
	$(CXX) $(CXXFLAGS) -Isrc \
	-c src/bellmanFord.cpp -o src/bellmanFord.o


# --------------------------------------------------
# Floyd-Warshall
# --------------------------------------------------

src/floydWarshall.o: src/floydWarshall.cpp src/floydWarshall.h
	$(CXX) $(CXXFLAGS) -Isrc \
	-c src/floydWarshall.cpp -o src/floydWarshall.o


# --------------------------------------------------
# CSR
# --------------------------------------------------

src/CSR.o: src/CSR.cpp src/CSR.h
	$(CXX) $(CXXFLAGS) -Isrc \
	-c src/CSR.cpp -o src/CSR.o


# --------------------------------------------------
# Clean
# --------------------------------------------------

clean:
	rm -f driver/*.o
	rm -f src/*.o
	rm -f $(TARGET)


.PHONY: all clean