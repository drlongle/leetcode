CXX     := g++
CXXFLAGS := -Wall -Wextra -Wno-unused-parameter -fno-strict-aliasing -std=c++14 -g -fno-omit-frame-pointer -fsanitize=address

all: solution

solution: solution.o
	$(CXX) $(CXXFLAGS) -o $@ solution.o -ldl -pthread -lasan

.cpp.o:
	${CXX} -c ${CXXFLAGS} $<

clean:
	rm -f solution *.o a.out *~

