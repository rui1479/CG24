CXX = g++
SRC_DIR = src/utils src/generator_src
SRC_FILES = $(wildcard $(addsuffix /*.cpp, $(SRC_DIR)))
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES))
EXECUTABLE = generator

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
