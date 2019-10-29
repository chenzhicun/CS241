assignment4:main.o GaussianElimination.o JacobiIteration.o
	g++ -o assignment4 main.o GaussianElimination.o JacobiIteration.o
JacobiIteration.o:JacobiIteration.cpp assignment4.h
	g++ -c JacobiIteration.cpp
GaussianElimination.o:GaussianElimination.cpp assignment4.h
	g++ -c GaussianElimination.cpp
main.o:main.cpp assignment4.h
	g++ -c main.cpp