CXX     := g++
CXXFLAGS := -Wall -Wextra -Wno-unused-parameter -fno-strict-aliasing -std=c++17 -g -fsanitize=address

all: solution

solution: solution.o
	$(CXX) -o $@ solution.o -ldl -pthread -lasan

.cpp.o:
	${CXX} -c ${CXXFLAGS} $<

clean:
	rm -f solution *.o a.out *~

