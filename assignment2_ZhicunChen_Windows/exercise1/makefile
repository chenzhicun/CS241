exercise1:main.o polynomial.o
	g++ -o exercise1 main.o polynomial.o
main.o:main.cpp polynomial.h
	g++ -c main.cpp
polynomial.o:polynomial.cpp polynomial.h
	g++ -c polynomial.cpp