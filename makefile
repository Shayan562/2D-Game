all:
	g++ -c main.cpp -o ../main.o && g++ ../main.o -o ../sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ../sfml-app