.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -std=c++11
PROGRAM = 010 011 012 013
all: $(PROGRAM)

010: 010.o
011: 011.o
012: 012.o
013: 013.o
010.o: 010.cpp
011.o: 011.cpp
012.o: 012.cpp
013.o: 013.cpp

## 適当
clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
