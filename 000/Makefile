.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -std=c++11
PROGRAM = 001 002 003
all: $(PROGRAM)

001: 001.o
002: 002.o
003: 003.o
001.o: 001.cpp
002.o: 002.cpp
003.o: 003.cpp

## 適当
clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
