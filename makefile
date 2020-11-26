CXX = g++
CXXFLAGS = -Wall

proj0: mytest.o
	$(CXX) $(CXXFLAGS) mytest.o -o proj0

mytest.o: stack.h mytest.cpp
	$(CXX) $(CXXFLAGS) -c mytest.cpp

run:
	./proj0

val:
	valgrind ./proj0

clean:
	rm *~
