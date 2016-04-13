.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 080 081
all: $(PROGRAM)

080: 080.o
080.o: 080.cpp
081: 081.o
081.o: 081.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
