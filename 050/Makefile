.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 050 051 052 053
all: $(PROGRAM)

050: 050.o
050.o: 050.cpp
051: 051.o
051.o: 051.cpp
052: 052.o
052.o: 052.cpp
053: 053.o
053.o: 053.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
