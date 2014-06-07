.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 040 041 042 043
all: $(PROGRAM)

040: 040.o
040.o: 040.cpp
041: 041.o
041.o: 041.cpp
042: 042.o
042.o: 042.cpp
043: 043.o
043.o: 043.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
