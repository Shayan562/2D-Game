all:
	g++ -c main.cpp -o ../main.o && g++ ../main.o -o ../game -lsfml-graphics -lsfml-window -lsfml-system && ../game





#output: main.o Game.o Player.o
#	g++ main.o Game.o Player.o -o ../game

#main.o: main.cpp
#	g++ -c main.cpp

#Game.o: src/Game.cpp src/Game.h
#	g++ -c src/Game.cpp

#Player.o: src/Player.cpp src/Player.h
#	g++ -c src/Player.cpp


#trying out 'all' method for make files
#all: 
#	g++ -c main.cpp src/Game.cpp src/Player.cpp -o ../main.o && g++ ../main.o -o ../game -lsfml-graphics -lsfml-window -lsfml-system && ../game
