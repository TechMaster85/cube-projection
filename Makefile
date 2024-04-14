CXX=g++
CXXFLAGS=-std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic -Wno-conversion -Wno-unused-variable

RELEASE_FLAGS=$(CXXFLAGS) -O3 -DNDEBUG
DEBUG_FLAGS=$(CXXFLAGS) -g3
FILES=*.cpp

LINK=SDL2
EXECUTABLE=cube-projection

APPLESILICON=

ifeq ($(shell uname),Darwin)
	ifeq ($(shell uname -m),arm64)
		APPLESILICON+=-I/opt/homebrew/include -L/opt/homebrew/lib
	endif
endif

main:
	$(CXX) $(FILES) $(RELEASE_FLAGS) $(APPLESILICON) -l$(LINK) -o $(EXECUTABLE)

debug:
	$(CXX) $(FILES) $(DEBUG_FLAGS) $(APPLESILICON) -l$(LINK) -o $(EXECUTABLE)_debug

clean:
	rm $(EXECUTABLE)*
