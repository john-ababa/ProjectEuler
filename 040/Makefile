.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 040 041 042 043 044 045 046 047 048 049
all: $(PROGRAM)

040: 040.o
040.o: 040.cpp
041: 041.o
041.o: 041.cpp
042: 042.o
042.o: 042.cpp
043: 043.o
043.o: 043.cpp
044: 044.o
044.o: 044.cpp
045: 045.o
045.o: 045.cpp
046: 046.o
046.o: 046.cpp
047: 047.o
047.o: 047.cpp
048: 048.o
048.o: 048.cpp
049: 049.o
049.o: 049.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
