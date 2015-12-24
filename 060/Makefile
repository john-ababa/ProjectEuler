.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 060 061 062 063 064 065 066
all: $(PROGRAM)

060: 060.o
060.o: 060.cpp
061: 061.o
061.o: 061.cpp
062: 062.o
062.o: 062.cpp
063: 063.o
063.o: 063.cpp
064: 064.o
064.o: 064.cpp
065: 065.o
065.o: 065.cpp
066: 066.o
066.o: 066.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
