CXX=g++
CXXFLAGS=-std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic -Wno-conversion

DEBUG_FLAGS=$(CXXFLAGS) -g3
RELEASE_FLAGS=$(CXXFLAGS) -O3 -DNDEBUG
# Update this if you have more .cpp files
FILES=*.cpp

LINK=SDL2
EXECUTABLE=cube-rotation

main:
	$(CXX) $(FILES) $(RELEASE_FLAGS) -I/opt/homebrew/include -L/opt/homebrew/lib -l$(LINK) -o $(EXECUTABLE)

debug:
	$(CXX) $(FILES) $(DEBUG_FLAGS) -l$(LINK) -o $(EXECUTABLE)_debug

clean:
	rm $(EXECUTABLE)*