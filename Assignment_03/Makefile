CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = program


# ------------------------------------------------------------
# Source files
# ------------------------------------------------------------

SRC = driver/main.cpp \
      src/prims.cpp \
      src/kruskal.cpp \
      ../Assignment_02/src/csr.cpp


# ------------------------------------------------------------
# Object files
# ------------------------------------------------------------

OBJ = driver/main.o \
      src/prims.o \
      src/kruskal.o \
      ../Assignment_02/src/csr.o


# ------------------------------------------------------------
# Default target
# ------------------------------------------------------------

all: $(TARGET)


# ------------------------------------------------------------
# Link
# ------------------------------------------------------------

$(TARGET): $(OBJ)

	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)


# ------------------------------------------------------------
# Compile main.cpp
# ------------------------------------------------------------

driver/main.o: driver/main.cpp

	$(CXX) $(CXXFLAGS) \
	-I../Assignment_02/src \
	-Isrc \
	-c driver/main.cpp \
	-o driver/main.o


# ------------------------------------------------------------
# Compile Prim's
# ------------------------------------------------------------

src/prims.o: src/prims.cpp src/prims.h src/mst.h

	$(CXX) $(CXXFLAGS) \
	-I../Assignment_02/src \
	-Isrc \
	-c src/prims.cpp \
	-o src/prims.o


# ------------------------------------------------------------
# Compile Kruskal
# ------------------------------------------------------------

src/kruskal.o: src/kruskal.cpp src/kruskal.h src/mst.h

	$(CXX) $(CXXFLAGS) \
	-I../Assignment_02/src \
	-Isrc \
	-c src/kruskal.cpp \
	-o src/kruskal.o


# ------------------------------------------------------------
# Compile CSR from Assignment 02
# ------------------------------------------------------------

../Assignment_02/src/csr.o: ../Assignment_02/src/csr.cpp \
                            ../Assignment_02/src/csr.h

	$(CXX) $(CXXFLAGS) \
	-I../Assignment_02/src \
	-c ../Assignment_02/src/csr.cpp \
	-o ../Assignment_02/src/csr.o


# ------------------------------------------------------------
# Clean
# ------------------------------------------------------------

clean:

	rm -f driver/*.o
	rm -f src/*.o
	rm -f ../Assignment_02/src/csr.o
	rm -f $(TARGET)


.PHONY: all clean