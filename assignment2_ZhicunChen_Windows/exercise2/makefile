exercise2:main.o NewtonInterpolation.o
	g++ -o exercise2 main.o NewtonInterpolation.o
main.o:main.cpp NewtonInterpolation.h
	g++ -c main.cpp
NewtonInterpolation.o:NewtonInterpolation.cpp NewtonInterpolation.h
	g++ -c NewtonInterpolation.cpp