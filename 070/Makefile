.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 070 071 072
all: $(PROGRAM)

070: 070.o
070.o: 070.cpp
071: 071.o
071.o: 071.cpp
072: 072.o
072.o: 072.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
