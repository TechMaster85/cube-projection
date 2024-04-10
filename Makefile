CXX=g++
CXXFLAGS=-std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic -Wno-conversion

DEBUG_FLAGS=$(CXXFLAGS) -g3
RELEASE_FLAGS=$(CXXFLAGS) -O3 -DNDEBUG
# Update this if you have more .cpp files
FILES=*.cpp

LINK=SDL2
EXECUTABLE=cube-rotation

APPLESILICON=

ifeq ($(shell uname),Darwin)
	ifeq ($(shell uname -m),arm64)
		APPLESILICON+=-I/opt/homebrew/include -L/opt/homebrew/lib
	endif
endif

main:
	$(CXX) $(FILES) $(RELEASE_FLAGS) $(APPLESILICON) -l$(LINK) -o $(EXECUTABLE)

debug:
	$(CXX) $(FILES) $(DEBUG_FLAGS) -l$(LINK) -o $(EXECUTABLE)_debug

clean:
	rm $(EXECUTABLE)*