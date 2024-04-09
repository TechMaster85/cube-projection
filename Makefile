CXX=g++
CXXFLAGS=-std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

DEBUG_FLAGS=$(CXXFLAGS) -g3
RELEASE_FLAGS=$(CXXFLAGS) -O3 -DNDEBUG
# Update this if you have more .cpp files
FILES=*.cpp

LINK=SDL2
EXECUTABLE=cube-rotation

main:
	$(CXX) $(FILES) $(RELEASE_FLAGS) -l$(LINK) -o $(EXECUTABLE)

debug:
	$(CXX) $(FILES) $(DEBUG_FLAGS) -l$(LINK) -o $(EXECUTABLE)_debug

clean:
	rm $(EXECUTABLE)*