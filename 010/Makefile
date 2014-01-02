.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -std=c++11
PROGRAM = 010 011 012 013 014 015 016 017 018 019
all: $(PROGRAM)

010: 010.o
011: 011.o
012: 012.o
013: 013.o
014: 014.o
015: 015.o
016: 016.o
017: 017.o
018: 018.o
019: 019.o
010.o: 010.cpp
011.o: 011.cpp
012.o: 012.cpp
013.o: 013.cpp
014.o: 014.cpp
015.o: 015.cpp
016.o: 016.cpp
017.o: 017.cpp
018.o: 018.cpp
019.o: 019.cpp

## 適当
clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
