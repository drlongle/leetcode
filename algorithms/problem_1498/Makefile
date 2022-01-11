CXX     := g++
CXXFLAGS := -Wall -Wextra -pedantic -Wno-unused-parameter -fno-strict-aliasing -std=c++20 -g -fsanitize=address -ftrapv

all: solution

solution: solution.o
	$(CXX) -o $@ solution.o -ldl -pthread -lasan

.cpp.o:
	${CXX} -c ${CXXFLAGS} $<

clean:
	rm -f solution *.o a.out *~

