CXX     := g++
CXXFLAGS := -Wall -Wextra -pedantic -Wno-unused-parameter -Werror -Wreturn-type -fno-strict-aliasing -std=c++20 -g -fsanitize=address -fsanitize=undefined -fsanitize=signed-integer-overflow
SOURCES = solution.cpp

all: solution

solution: solution.o
	$(CXX) -o $@ solution.o -ldl -pthread -lasan -lubsan

.cpp.o:
	${CXX} -c ${CXXFLAGS} $<

tidy: $(SOURCES)
	clang-tidy -checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus* $(SOURCES)

check: $(SOURCES)
	cppcheck . --enable=all

clean:
	rm -f solution *.o a.out *~

