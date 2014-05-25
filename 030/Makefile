.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 030 031 032 033 034 035 036 037
all: $(PROGRAM)

030: 030.o
030.o: 030.cpp
031: 031.o
031.o: 031.cpp
032: 032.o
032.o: 032.cpp
033: 033.o
033.o: 033.cpp
034: 034.o
034.o: 034.cpp
035: 035.o
035.o: 035.cpp
036: 036.o
036.o: 036.cpp
037: 037.o
037.o: 037.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
