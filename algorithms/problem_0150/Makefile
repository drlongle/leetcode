CXX     := g++
CXXFLAGS := -Wall -Wextra -Wno-unused-parameter -fno-strict-aliasing -std=c++11 -g -fsanitize=undefined

all: solution

solution: solution.o
	$(CXX) $(CXXFLAGS) -o $@ solution.o -ldl -pthread

.cpp.o:
	${CXX} -c ${CXXFLAGS} $<

clean:
	rm -f solution *.o a.out *~

