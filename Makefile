CC=g++
CFLAGS=-c -Wall

SOURCE_DIR=src
BUILD_DIR=build

# define .cpp for modules
BOUND_COND_CPP = $(SOURCE_DIR)/boundary_conditions/DerichleBoundaryCondition.cpp $(SOURCE_DIR)/boundary_conditions/NeumanBoundaryCondition.cpp
PLATE_CPP = $(SOURCE_DIR)/plate/plate.cpp $(SOURCE_DIR)/plate/plate_discret.cpp $(SOURCE_DIR)/plate/mkrpoint.cpp
UTILS_CPP = $(SOURCE_DIR)/utils/boundary.cpp $(SOURCE_DIR)/utils/utils.cpp
SOLVER_CPP = $(SOURCE_DIR)/solver/gauss_seidel.cpp

SOURCES=$(BOUND_COND_CPP) $(PLATE_CPP) $(UTILS_CPP) $(SOLVER_CPP) $(SOURCE_DIR)/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: mkr

debug: CFLAGS+=-g -DDEBUG
debug: mkr

mkr: object_dir $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/mkr
	rm -rf $(SOURCE_DIR)/**/*.o

object_dir:
	mkdir -p build

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(SOURCE_DIR)/**/*.o $(BUILD_DIR)/mkr
