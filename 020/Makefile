.PHONY: all clean
.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -O0 -Wall -Wextra -std=c++11
PROGRAM = 020 021 022 023 024 025 026 027
all: $(PROGRAM)

020: 020.o
021: 021.o
022: 022.o
023: 023.o
024: 024.o
025: 025.o
026: 026.o
027: 027.o
020.o: 020.cpp
021.o: 021.cpp
022.o: 022.cpp
023.o: 023.cpp
024.o: 024.cpp
025.o: 025.cpp
026.o: 026.cpp
027.o: 027.cpp

clean:
	rm -f $(PROGRAM) *.o
.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<
%:
	$(CXX) $(CXXFLAGS) -o $@ $^
