.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 030 031 032 033
all: $(PROGRAM)

030: 030.o
030.o: 030.cpp
031: 031.o
031.o: 031.cpp
032: 032.o
032.o: 032.cpp
033: 033.o
033.o: 033.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
