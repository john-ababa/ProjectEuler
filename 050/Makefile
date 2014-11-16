.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 050 051 052 053 054 055 056 057 058
all: $(PROGRAM)

050: 050.o
050.o: 050.cpp
051: 051.o
051.o: 051.cpp
052: 052.o
052.o: 052.cpp
053: 053.o
053.o: 053.cpp
054: 054.o
054.o: 054.cpp
055: 055.o
055.o: 055.cpp
056: 056.o
056.o: 056.cpp
057: 057.o
057.o: 057.cpp
058: 058.o
058.o: 058.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
