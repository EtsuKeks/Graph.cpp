CC=g++
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage -std=c++17

all: tests
tests.o: tests.cpp
	${CC} -c tests.cpp -o tests.o ${CFLAGS}
stack.o: graph.cpp
	${CC} -c graph.cpp -o graph.o ${CFLAGS}
tests: tests.o graph.o
	${CC} graph.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../graph_cpp.tgz ../graph_cpp
