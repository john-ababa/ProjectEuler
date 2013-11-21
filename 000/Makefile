.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -std=c++11
PROGRAM = 001 002 003 004 005 006 007 008 009
all: $(PROGRAM)

001: 001.o
002: 002.o
003: 003.o
004: 004.o
005: 005.o
006: 006.o
007: 007.o
008: 008.o
009: 009.o
001.o: 001.cpp
002.o: 002.cpp
003.o: 003.cpp
004.o: 004.cpp
005.o: 005.cpp
006.o: 006.cpp
007.o: 007.cpp
008.o: 008.cpp
009.o: 009.cpp

## 適当
clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
