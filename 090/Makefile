.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 090 091 092 093
all: $(PROGRAM)

090: 090.o
090.o: 090.cpp
091: 091.o
091.o: 091.cpp
092: 092.o
092.o: 092.cpp
093: 093.o
093.o: 093.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
