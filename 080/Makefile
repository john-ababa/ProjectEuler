.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 080 081 082 083 084 085 086 087 088 089
all: $(PROGRAM)

080: 080.o
080.o: 080.cpp
081: 081.o
081.o: 081.cpp
082: 082.o
082.o: 082.cpp
083: 083.o
083.o: 083.cpp
084: 084.o
084.o: 084.cpp
085: 085.o
085.o: 085.cpp
086: 086.o
086.o: 086.cpp
087: 087.o
087.o: 087.cpp
088: 088.o
088.o: 088.cpp
089: 089.o
089.o: 089.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
