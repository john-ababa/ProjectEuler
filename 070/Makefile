.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 070 071 072 073 074 075 076 077
all: $(PROGRAM)

070: 070.o
070.o: 070.cpp
071: 071.o
071.o: 071.cpp
072: 072.o
072.o: 072.cpp
073: 073.o
073.o: 073.cpp
074: 074.o
074.o: 074.cpp
075: 075.o
075.o: 075.cpp
076: 076.o
076.o: 076.cpp
077: 077.o
077.o: 077.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
