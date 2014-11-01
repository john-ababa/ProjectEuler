.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 050 051
all: $(PROGRAM)

050: 050.o
050.o: 050.cpp
051: 051.o
051.o: 051.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
