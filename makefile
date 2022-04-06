all:
	g++ -c main.cpp -o ../main.o && g++ ../main.o -o ../game -lsfml-graphics -lsfml-window -lsfml-system && ../game